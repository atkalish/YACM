#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <stdexcept>

using namespace std;
using namespace nlohmann;

class JsonSerializer{
private:
    json data;

public:
    template<class T> void put(const std::string& key, const T& value){
        this->data[key] = value;
    }

    template <typename T> void addToList(const string& key, const T& value){
        json list = this->data[key];
        if(!list.is_array()){
            list = json::array();
        }
        list.push_back(value);
        this->data[key] = list;
    }

    string str();
    void exportJson(const string& filepath);
};


