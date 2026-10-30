#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include "../logger/Logger.h"
#include <stdexcept>

using namespace std;
using namespace nlohmann;

class JsonDeserializer{
private:
    json data;

public:
    JsonDeserializer(const string& jsonPath);
    JsonDeserializer() = default;

    template <typename T> T get(const string& key) const;
};