#include "IR_Operator.h"

IR_Operator::IR_Operator() {
    //cout << "Call constructor IR_Operator()" << endl;
    id = "No id for operator";
    type = "Terminal";
    inputData = nullptr;
    outputData = nullptr;
    nestedOperators = nullptr;
    inputData_size = 0;
    outputData_size = 0;
    nestedOperators_size = 0;

    //showAll();
}

IR_Operator::IR_Operator(const IR_Operator& obj)
{
    //cout << "Call COPY constructor IR_Operator()" << endl;
    inputData = nullptr;
    outputData = nullptr;
    nestedOperators = nullptr;
    id = obj.id;
    type = obj.type;
    if (obj.inputData_size > 0) {
        inputData = new IR_DataObject *[obj.inputData_size];
        for (int i = 0; i < obj.inputData_size; i++) {
            *(inputData + i) = *(obj.inputData + i);
        }
    }
    if (obj.outputData_size > 0){
        outputData = new IR_DataObject*[obj.outputData_size];
        for(int i = 0; i < obj.outputData_size;i++){
            *(outputData+i)=*(obj.outputData+i);
        }
    }

    if (obj.nestedOperators_size > 0){
        nestedOperators = new IR_Operator*[obj.nestedOperators_size];
        for(int i = 0; i < obj.nestedOperators_size;i++){
            *(nestedOperators+i)=*(obj.nestedOperators+i);
        }
    }

    outputData_size = obj.outputData_size;
    inputData_size = obj.inputData_size;
    nestedOperators_size = obj.nestedOperators_size;
}

IR_Operator::~IR_Operator() {
    //cout << "Call destructor ~IR_Operator()" << endl;

    if (inputData != nullptr)
        delete[] inputData;
    if (outputData != nullptr)
        delete[] outputData;
//    if (nestedOperators != nullptr)
    if (nestedOperators_size > 0)
        delete[] nestedOperators;
    inputData_size = 0;
    outputData_size = 0;
    nestedOperators_size = 0;

    //showAll();
}

void IR_Operator::addInputData(IR_DataObject& newInputData) {
    cout << endl << "Call IR_Operator::addInputData("<< &newInputData << ")" << endl;

    if (inputData == nullptr) {
        inputData = new IR_DataObject*[1];
        inputData[0] = &newInputData;
        inputData_size = 1;
    }
    else {
        IR_DataObject** bufInputData = new IR_DataObject*[inputData_size + 1];
        for (size_t i = 0; i < inputData_size; i++) {
            bufInputData[i] = inputData[i];
        }
        bufInputData[inputData_size] = &newInputData;
        delete[] inputData;
        inputData = bufInputData;
        inputData_size++;
    }

    //showAll();
}

void IR_Operator::addOutputData(IR_DataObject& newOutputData) {
    cout << endl << "Call IR_Operator::addOutputData(" << &newOutputData << ")" << endl;

    if (outputData == nullptr) {
        outputData = new IR_DataObject * [1];
        outputData[0] = &newOutputData;
        outputData_size = 1;
    }
    else {
        IR_DataObject** bufOutputData = new IR_DataObject * [outputData_size + 1];
        for (size_t i = 0; i < outputData_size; i++) {
            bufOutputData[i] = outputData[i];
        }
        bufOutputData[outputData_size] = &newOutputData;
        delete[] outputData;
        outputData = bufOutputData;
        outputData_size++;
    }

    //showAll();
}

void IR_Operator::addNestedOperators(IR_Operator& newNestedOperators) {
    cout << endl << "Call IR_Operator::addNestedOperators(" << &newNestedOperators << ")" << endl;

    if (nestedOperators == nullptr) {
        nestedOperators = new IR_Operator * [1];
        nestedOperators[0] = &newNestedOperators;
        nestedOperators_size = 1;
    }
    else {
        IR_Operator** bufNestedOperators = new IR_Operator * [nestedOperators_size + 1];
        for (size_t i = 0; i < nestedOperators_size; i++) {
            bufNestedOperators[i] = nestedOperators[i];
        }
        bufNestedOperators[nestedOperators_size] = &newNestedOperators;
        delete[] nestedOperators;
        nestedOperators = bufNestedOperators;
        nestedOperators_size++;
    }

    //showAll();
}

void IR_Operator::setId(ID_type id) {
    this->id = id;
}

ID_type IR_Operator::getId() {
    return id;
}
void IR_Operator::setType(OperatorType type) {
    this->type = type;
}
OperatorType IR_Operator::getType() {
    return type;
}

void IR_Operator::clear()
{
    cout << "Call clear IR_Operator()" << endl;
    id = "No id for operator";
    type = "Terminal";
    inputData = nullptr;
    outputData = nullptr;
    nestedOperators = nullptr;
    inputData_size = 0;
    outputData_size = 0;
    nestedOperators_size = 0;
}

void IR_Operator::showAll() {
    showIdAndType();
    showInputData();
    showOutputData();
    showNestedOperators();
}
void IR_Operator::showIdAndType(){
    fout.open("file.txt", ios::app);
    cout << "  id = " << id << "  type = " << type << endl;
    fout << "  id = " << id << "  type = " << type << endl;
    fout.close();
}
void IR_Operator::showInputData(){

    //cout << "  inputData: size = "<< inputData_size << endl;
    fout.open("file.txt", ios::app);
    for (size_t i = 0; i < inputData_size; i++) {
        cout << "    Data ";
        cout << "id = " << inputData[i]->getId();
        cout << "  type = " << inputData[i]->getType();
        cout << "  path = " << inputData[i]->getPath();
        cout << "  connect_type = input";
        cout << "  access_time = " << inputData[i]->getAccessTime();
        cout << "  value = " << inputData[i]->getValue();
        cout << endl;

        fout << "    Data ";
        fout << "id = " << inputData[i]->getId();
        fout << "  type = " << inputData[i]->getType();
        fout << "  path = " << inputData[i]->getPath();
        fout << "  connect_type = input";
        fout << "  access_time = " << inputData[i]->getAccessTime();
        fout << "  value = " << inputData[i]->getValue();
        fout << endl;
    }
    fout.close();
}

void IR_Operator::showOutputData() {
    //cout << "  outputData: size = " << outputData_size << endl;
    fout.open("file.txt", ios::app);
    for (size_t i = 0; i < outputData_size; i++) {
        cout << "    Data ";
        cout << "id = " << outputData[i]->getId();
        cout << "  type = " << outputData[i]->getType();
        cout << "  path = " << outputData[i]->getPath();
        cout << "  connect_type = output";
        cout << "  access_time = " << outputData[i]->getAccessTime();
        cout << "  value = " << outputData[i]->getValue();
        cout << endl;

        fout << "    Data ";
        fout << "id = " << outputData[i]->getId();
        fout << "  type = " << outputData[i]->getType();
        fout << "  path = " << outputData[i]->getPath();
        fout << "  connect_type = output";
        fout << "  access_time = " << outputData[i]->getAccessTime();
        fout << "  value = " << outputData[i]->getValue();
        fout << endl;
    }
    fout.close();


}

void IR_Operator::showNestedOperators() {
//    cout << "  nestedOperators: size = " << nestedOperators_size << endl;
//    for (size_t i = 0; i < nestedOperators_size; i++) {
//        cout << "    Operator " << i << nestedOperators[i] << endl;
//    }
    fout.open("file.txt", ios::app);
    for (size_t i = 0; i < nestedOperators_size; i++) {
        nestedOperators[i]->showAll();
    }
    fout.close();
}
