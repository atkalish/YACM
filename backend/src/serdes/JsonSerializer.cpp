#include "../../include/serdes/JsonSerializer.h"

void JsonSerializer::createList(const string& key){
    this->data[key] = json::array();
}

void JsonSerializer::createTable(const string& key, int size){
    this->data[key] = json::array();
    for(int i = 0; i < size; ++i) this->data[key][i] = json::array();
}

string JsonSerializer::str(){
    return this->data.dump();
}