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
	string path;

public:
    JsonDeserializer(const string& jsonPath);
    JsonDeserializer() = default;

	template<typename T, typename... Args>
	T get(const Args&... key) const {
		json tmp = data;
		([&] {
			if(!tmp.contains(key)) throw runtime_error("Invalid Key: "s + key + " in "s + this->path);
			tmp = tmp[key];
		} (), ...);
		if constexpr (std::is_same_v<T, JsonDeserializer>) return JsonDeserializer(tmp, this->path);
		if constexpr (std::is_same_v<T, vector<JsonDeserializer>>){
		 	vector<JsonDeserializer> jds;
			for(int i = 0; i < tmp.size(); ++i) jds.push_back(JsonDeserializer(tmp[i], this->path));
			return jds;
		}
		else return tmp;
	}

private:
	JsonDeserializer(const json& j, const string& path);
};
