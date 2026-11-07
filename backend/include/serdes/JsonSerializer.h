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
        if constexpr (std::is_convertible_v<T, std::string>) {
            std::string str_value = value;
            if(json::accept(str_value)){
                this->data[key] = json::parse(str_value);
            }else{
                this->data[key] = str_value;
            }
        }else{
            this->data[key] = value;
        }
    }

    template <typename T> void addToList(const string& key, const T& value){
        json list = this->data[key];
        if(!list.is_array()){
            list = json::array();
        }
        if constexpr (std::is_convertible_v<T, std::string>) {
            std::string str_value = value;
            if (json::accept(str_value)) {
                list.push_back(json::parse(str_value));
            }else{
                list.push_back(str_value);
            }
        }else{
            list.push_back(value);
        }
        this->data[key] = list;
    }

    void createList(const string& key);

    string str();
    void exportJson(const string& filepath);
};