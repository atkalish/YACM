#include "../../include/serdes/JsonDeserializer.h"
#include <stdexcept>

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

template <typename T> T JsonDeserializer::get(const string& key) const {
    if(!this->data.contains(key)) throw runtime_error("Invalid Key: "s + key);
    return this->data[key];
}
template int JsonDeserializer::get<int>(const std::string& key) const;
template bool JsonDeserializer::get<bool>(const std::string& key) const;
template string JsonDeserializer::get<string>(const std::string& key) const;
template vector<string> JsonDeserializer::get<vector<string>>(const std::string& key) const;
template vector<vector<int>> JsonDeserializer::get<vector<vector<int>>>(const std::string& key) const;
template vector<vector<string>> JsonDeserializer::get<vector<vector<string>>>(const std::string& key) const;

template <typename T> T JsonDeserializer::get(const std::string& key, const std::string& weakKey) {
	if(!this->data.contains(key)) throw runtime_error("Invalid Key: "s + key);
	if(!this->data[key].contains(weakKey))throw runtime_error("Invalid weak key: "s + weakKey + " with key " + key);

	return this->data[key][weakKey];
}

template int JsonDeserializer::get<int>(const std::string& key, const std::string& weakKey) const;
template bool JsonDeserializer::get<bool>(const std::string& key, const std::string& weakKey) const;
template string JsonDeserializer::get<string>(const std::string& key, const std::string& weakKey) const;
template vector<string> JsonDeserializer::get<vector<string>>(const std::string& key, const std::string& weakKey) const;
template vector<vector<int>> JsonDeserializer::get<vector<vector<int>>>(const std::string& key, const std::string& weakKey) const;
template vector<vector<string>> JsonDeserializer::get<vector<vector<string>>>(const std::string& key, const std::string& weakKey) const;
