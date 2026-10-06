#pragma once
#include "features/Ability.h"

using namespace std;

class Item{
private:
	string name;
	string description;
	vector<Ability*> abilities;
public:
	class Builder {
	private:
		string _name;
		string _description;
		vector<Ability*> _abilities;
	public:
		Builder() = default;
		Builder& name(const string& name){this->_name = name; return *this;}
		Builder& description(const string& description){this->_description = description; return *this;}
		Builder& abilities(const vector<Ability*>& abilities) {this->_abilities = abilities; return *this;}
		Item build() {return Item(this);}

		friend class Item;
	};

	Item(Builder* builder) {
		this->name = builder->_name;
		this->description = builder->_description;
		this->abilities = builder->_abilities;
	}

	~Item();
	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
	const vector<Ability*>& getAbilities() const {return this->abilities;}
};
