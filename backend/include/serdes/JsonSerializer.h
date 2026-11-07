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
        if constexpr (std::is_convertible_v<T, std::string>){
            string str_value = value;
            if(json::accept(str_value)){
                this->data[key] = json::parse(str_value);
            }else{
                this->data[key] = str_value;
            }
        }else{
            this->data[key] = value;
        }
    }

    void createList(const string& key);

    template <typename T> void addToList(const string& key, const T& value){
        json list = this->data[key];
        if(!list.is_array()){
            list = json::array();
        }
        if constexpr (std::is_convertible_v<T, std::string>){
            string str_value = value;
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

    void createTable(const string& key, int size);

    template <typename T> void addToTable(const string& key, int i, const T& value){
        json list = this->data[key][i];
        if constexpr (std::is_convertible_v<T, std::string>){
            string str_value = value;
            if(json::accept(str_value)){
                list.push_back(json::parse(str_value));
            }else{
                list.push_back(str_value);
            }
        }else{
            list.push_back(value);
        }
        this->data[key][i] = list;
    }

    string str();
    void exportJson(const string& filepath);
};