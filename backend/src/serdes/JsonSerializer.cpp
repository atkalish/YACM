#include "../../include/serdes/JsonSerializer.h"

void JsonSerializer::createList(const string& key){
    this->data[key] = json::array();
}

string JsonSerializer::str(){
    return this->data.dump();
}