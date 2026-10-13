#pragma once
#include "features/Feature.h"

using namespace std;

class Item{
private:
	string name;
	string description;
	vector<Feature> features;
public:
	class Builder {
	private:
		string _name;
		string _description;
		vector<Feature> _features;
	public:
		Builder() = default;
		Builder& name(const string& name){this->_name = name; return *this;}
		Builder& description(const string& description){this->_description = description; return *this;}
		Builder& abilities(const vector<Feature>& features) {this->_features = features; return *this;}
		Item build() {return Item(this);}

		friend class Item;
	};

	Item(Builder* builder) {
		this->name = builder->_name;
		this->description = builder->_description;
		this->features = builder->_features;
	}

	~Item();
	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
	const vector<Feature>& getFeatures() const {return this->features;}
};
