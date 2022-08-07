cmake_minimum_required(VERSION 3.21)
project(front_end_RVM_compiler)

set(CMAKE_CXX_STANDARD 14)

#add_executable(front_end_RVM_compiler main.cpp sources/IR_DataObject.cpp sources/IR_DataObject.h sources/IR_Operator.cpp sources/IR_Operator.h sources/parseXMLfunctions.h sources/parseXMLfunctions.cpp sources/LogManager.cpp sources/LogManager.h sources/configCodeStructure.h)
add_executable(front_end_RVM_compiler

                pugixml/pugiconfig.hpp
                pugixml/pugixml.hpp
                pugixml/pugixml.cpp
                include/ir_data.h
                include/ir_operator.h
                include/ir_link.h
                src/ir_data.cpp
                src/ir_operator.cpp
                src/ir_link.cpp
                src/main.cpp
        include/frontend_compiler.h src/frontend_compiler.cpp tests/include/test_ir_objects.h tests/src/test_ir_objects.cpp)
