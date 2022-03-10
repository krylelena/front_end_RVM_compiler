#include "IR_DataObject.h"

IR_DataObject::IR_DataObject() {
    id = "No id for data";
    type = "float";
    accessTime = "10";
    state = "No state";
    value = "";
}
IR_DataObject::~IR_DataObject() {}

void IR_DataObject::setId(ID_type newId) {
    id = newId;
}
ID_type IR_DataObject::getId() {
    return id;
}

void IR_DataObject::setType(DataType newType) {
    type = newType;
}
DataType IR_DataObject::getType() {
    return type;
}

void IR_DataObject::setAccessTime(AccessTimeType newAccessTime){
    accessTime = newAccessTime;
}
AccessTimeType IR_DataObject::getAccessTime(){
    return accessTime;
}

void IR_DataObject::setState(StateType state)
{
    this->state = state;
}

StateType IR_DataObject::getState()
{
    return state;
}

void IR_DataObject::setValue(ValueType value)
{
    this->value = value;
}

ValueType IR_DataObject::getValue()
{
    return value;
}

void IR_DataObject::clear() {
    id = "No id for data";
    type = "float";
    accessTime = "10";
    state = "No state";
    value = "";
}

void IR_DataObject::setPath(PathType path) {
    this->path = path;
}

PathType IR_DataObject::getPath(){
    return path;
}

