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

	template<typename T, typename... Args>
	T get(const Args&... key) const {
		json tmp = data;
		([&] {
			if(!tmp.contains(key)) throw runtime_error("Invalid Key: "s + key);
			tmp = tmp[key];
		} (), ...);
		return tmp;
	}


		//template <typename T> T get(const string& key) const;
		
    //template <typename T> T get(const string& key) const;
		//template <typename T> T get(const string& key, const string& weakKey) const; // WARNING: not implemented
};
