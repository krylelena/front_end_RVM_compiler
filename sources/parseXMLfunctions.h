//
// Created by Елена on 10.12.2021.
//

#ifndef FRONT_END_RVM_COMPILER_PARSEXMLFUNCTIONS_H
#define FRONT_END_RVM_COMPILER_PARSEXMLFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include "../rapidXML/rapidxml.hpp"
#include "IR_Operator.h"
#include "IR_DataObject.h"

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


#endif //FRONT_END_RVM_COMPILER_PARSEXMLFUNCTIONS_H
