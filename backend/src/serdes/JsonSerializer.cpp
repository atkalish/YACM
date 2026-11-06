#include "../../include/serdes/JsonSerializer.h"

string JsonSerializer::str(){
    return this->data.dump();
}