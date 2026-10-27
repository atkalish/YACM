#pragma once

#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

class JsonDeserializer{
private:
    json j;

public:
    JsonDeserializer(const string& jsonPath);
    JsonDeserializer() = delete;

    template <typename T>
    T get<T>(const string& key) const;
};