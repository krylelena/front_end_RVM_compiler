cmake_minimum_required(VERSION 3.21)
project(front_end_RVM_compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(front_end_RVM_compiler main.cpp sources/IR_DataObject.cpp sources/IR_DataObject.h sources/IR_Operator.cpp sources/IR_Operator.h sources/parseXMLfunctions.h sources/parseXMLfunctions.cpp sources/LogManager.cpp sources/LogManager.h sources/configCodeStructure.h)
