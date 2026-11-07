#pragma once
#include "features/Feature.h"
#include "../serdes/JsonDeserializer.h"
#include "../serdes/JsonSerializer.h"

using namespace std;

class Item{
private:
	string name;
	string description;
public:
	inline static const string SRC_DIR = "data/resources/items/";
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

	string serialize() const;
	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
};
