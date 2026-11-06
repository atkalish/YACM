#include "../../include/serdes/JsonDeserializer.h"

JsonDeserializer::JsonDeserializer(const string& jsonPath){
    ifstream inFile(jsonPath);
    if(!inFile.is_open()) throw runtime_error("Unable to open file: "s + jsonPath);
 
    try{
        this->data = json::parse(inFile);
    }catch(...){
        throw runtime_error("Failed to parse file: "s + jsonPath);
    }
    inFile.close();
    
    Logger* logger = Logger::getInstance();
    logger->log("Parsed JSON: "s + jsonPath);
}
