//
// Created by Елена on 10.12.2021.
//
#include "parseXMLfunctions.h"

void testXML() {
    cout << "\nParsing my graph ....." << endl;
    xml_document<> doc;
    xml_node<> *root_node = NULL;

    // Read the sample.xml file
    ifstream theFile("../XML_files/AlgScalar2.xml");
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer
    doc.parse<0>(&buffer[0]);

    // Find out the root node
    root_node = doc.first_node("program");

    parseProgram(*root_node);

}

void parseProgram(xml_node<> &root_node) {
    vector<IR_Operator> arrProgram;
    list<IR_Operator> OperatorHeap;
    list<IR_DataObject> DataHeap;

    parseHighLevelOperator(root_node, arrProgram, OperatorHeap, DataHeap);

    cout << endl;
    for (auto el: arrProgram) {
        el.showAll();
        cout << endl;
    }
    cout << DataHeap.size() << endl;
}

void parseHighLevelOperator(xml_node<> &parentOperator_node, vector<IR_Operator> &arrProgram,
                            list<IR_Operator> &OperatorHeap, list<IR_DataObject> &DataHeap) {
    map<string, IR_DataObject> arrInData;
    map<string, IR_DataObject> arrOutData;
    int local_arrNestedOperator = 0;
    IR_Operator currentOperator;

    for (xml_node<> *operator_node = (&parentOperator_node)->first_node(
            "operator"); operator_node; operator_node = operator_node->next_sibling()) {
        currentOperator.setId(operator_node->first_attribute("id")->value());
        currentOperator.setType(operator_node->first_attribute("type")->value());

        if (currentOperator.getType() == "Complex") {
            parseOperator(*operator_node, local_arrNestedOperator, OperatorHeap, DataHeap);

            auto it_end = OperatorHeap.end();
            for (int i = 0; i < local_arrNestedOperator; i++){
                --it_end;
            }
            for (int i = 0; i < local_arrNestedOperator; i++) {
                currentOperator.addNestedOperators(*it_end);
                ++it_end;
            }

        }

        //*************************************************************************************************************************
        parseData(*operator_node, arrInData, arrOutData);

        for (int i = 1; i < arrInData.size() + 1; i++) {
            IR_DataObject bufData = arrInData[to_string(i)];
            if (!searchData(DataHeap, bufData)) {
                DataHeap.push_back(bufData);
            }
            IR_DataObject *ptr = getData(DataHeap, bufData);
            currentOperator.addInputData(*ptr);
        }
        for (int i = 1; i < arrOutData.size() + 1; i++) {
            IR_DataObject bufData = arrOutData[to_string(i)];
            if (!searchData(DataHeap, bufData)) {
                DataHeap.push_back(bufData);
            }
            IR_DataObject *ptr = getData(DataHeap, bufData);
            currentOperator.addOutputData(*ptr);
        }
        arrProgram.push_back(currentOperator);
        currentOperator.clear();
        arrInData.clear();
        arrOutData.clear();
    }
}

void parseOperator(xml_node<> &parentOperator_node, int &arrNestedOperator,
                   list<IR_Operator> &OperatorHeap, list<IR_DataObject> &DataHeap) {

    map<string, IR_DataObject> arrInData;
    map<string, IR_DataObject> arrOutData;
    int local_arrNestedOperator = 0;
    IR_Operator currentOperator;

    for (xml_node<> *operator_node = (&parentOperator_node)->first_node(
            "operator"); operator_node; operator_node = operator_node->next_sibling()) {
        currentOperator.setId(operator_node->first_attribute("id")->value());
        currentOperator.setType(operator_node->first_attribute("type")->value());

        if (currentOperator.getType() == "Complex") {
            parseOperator(*operator_node, local_arrNestedOperator, OperatorHeap, DataHeap);

            auto it_end = OperatorHeap.end();
            for (int i = 0; i < local_arrNestedOperator; i++){
                --it_end;
            }
            for (int i = 0; i < local_arrNestedOperator; i++) {
                currentOperator.addNestedOperators(*it_end);
                ++it_end;
            }
        }
        //*************************************************************************************************************************
        parseData(*operator_node, arrInData, arrOutData);

        for (int i = 1; i < arrInData.size() + 1; i++) {
            IR_DataObject bufData = arrInData[to_string(i)];
           if (!searchData(DataHeap, bufData)) {
               DataHeap.push_back(bufData);
           }
            IR_DataObject *ptr = getData(DataHeap, bufData);
            currentOperator.addInputData(*ptr);
        }
        for (int i = 1; i < arrOutData.size() + 1; i++) {
            IR_DataObject bufData = arrOutData[to_string(i)];
            if (!searchData(DataHeap, bufData)) {
                DataHeap.push_back(bufData);
            }
            IR_DataObject *ptr = getData(DataHeap, bufData);
            currentOperator.addOutputData(*ptr);
        }

        OperatorHeap.push_back(currentOperator);
        arrNestedOperator++;
        currentOperator.clear();
        arrInData.clear();
        arrOutData.clear();
    }

}

void parseData(xml_node<> &operator_node, map<string,IR_DataObject> &arrInData, map<string, IR_DataObject> &arrOutData) {

    IR_DataObject currentData;

    for (xml_node<> *data_node = (&operator_node)->first_node("data"); data_node; data_node = data_node->next_sibling(
            "data")) {

        currentData.setId(data_node->first_attribute("id")->value());
        currentData.setType(data_node->first_attribute("type")->value());
        currentData.setPath(data_node->first_attribute("path")->value());
        currentData.setAccessTime(data_node->first_attribute("access_time")->value());
        currentData.setState(data_node->first_attribute("state")->value());

        string state = data_node->first_attribute("state")->value();

        if (state == "full") {
            currentData.setValue(data_node->first_attribute("value")->value());
        }
        string connect_type = data_node->first_attribute("connect_type")->value();
        string order = data_node->first_attribute("order")->value();
        if (connect_type == "input") {
            arrInData[order] = currentData;
        } else if (connect_type == "output") {
            arrOutData[order] = currentData;
        }

        currentData.clear();
    }
    cout << endl;
}

void fillingStructures() {
    struct ControlSection controlSection;

    controlSection.LCF = 1; //means that this is the last Configcode in the task
    controlSection.NAF = 0; //
    controlSection.Task_ID = 1;
    controlSection.RPI_version = 1; //version number of supported general radio programming interface
    controlSection.Reference_ID = 1; //identifier of the reference Radio Library
    controlSection.Implementation_version = 1;
    controlSection.Developer_ID = 1;
    controlSection.Creation_Date = 2022;
}

int searchData(list<IR_DataObject> &DataHeap, IR_DataObject &bufData) {
    for (auto const& elem : DataHeap) {
        if (elem.getId() == bufData.getId()){
            return 1;
        }
    }
    return 0;
}

IR_DataObject* getData(list<IR_DataObject> &DataHeap, IR_DataObject &bufData) {
    for (auto &elem : DataHeap) {
        if (elem.getId() == bufData.getId()){
            return &elem;
        }
    }
}