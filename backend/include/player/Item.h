#pragma once
#include "features/Feature.h"
#include "../serdes/JsonDeserializer.h"

using namespace std;

class Item{
private:
	inline static const string SRC_DIR = "data/resources/items/";
	string name;
	string description;
public:
	class Builder {
	private:
		string _name;
		string _description;
	public:
		Builder() = default;
		Builder& name(const string& name){this->_name = name; return *this;}
		Builder& description(const string& description){this->_description = description; return *this;}
		Item build() {return Item(this);}

		friend class Item;
	};

private:
	Item(Builder* builder) {
		this->name = builder->_name;
		this->description = builder->_description;
	}

public:
	Item(const string& jsonPath);
	Item() = default;
	~Item() = default;
	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
};
