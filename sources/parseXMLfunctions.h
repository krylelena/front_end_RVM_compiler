//
// Created by Елена on 10.12.2021.
//

#ifndef FRONT_END_RVM_COMPILER_PARSEXMLFUNCTIONS_H
#define FRONT_END_RVM_COMPILER_PARSEXMLFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include "../rapidXML/rapidxml.hpp"
#include "IR_Operator.h"
#include "IR_DataObject.h"
#include "configCodeStructure.h"

using namespace std;
using namespace rapidxml;

void testXML();

void parseProgram(xml_node<> &root_node);

void parseHighLevelOperator(xml_node<> &parentOperator_node, vector<IR_Operator> &arrProgram,
                            list<IR_Operator> &OperatorHeap, list<IR_DataObject> &DataHeap);

void parseOperator(xml_node<> &parentOperator_node, int &arrNestedOperator, list<IR_Operator> &OperatorHeap,
                   list<IR_DataObject> &DataHeap);

void parseData(xml_node<> &operator_node, map<string, IR_DataObject> &arrInData, map<string,
               IR_DataObject> &arrOutData);

void fillingStructures(vector<IR_Operator> &arrProgram, list<IR_Operator> &OperatorHeap, list<IR_DataObject> &DataHeap);
void filligControlSections(struct ControlSection & controlSection);

// other functions
int searchData(list<IR_DataObject> &DataHeap, IR_DataObject &bufData);

IR_DataObject* getData(list<IR_DataObject> &DataHeap, IR_DataObject &bufData);

#endif //FRONT_END_RVM_COMPILER_PARSEXMLFUNCTIONS_H
