#pragma once
#include "features/Feature.h"
#include "features/TraitModification.h"
#include "features/Selector.h"

class Race {
private:
	string name;
	int speed;
	string description;
	vector<Feature> features;

public:
	class Builder {
	private:
		string _name;
		string _description;
		int _speed;
		vector<Feature> _features;
	public:
		Builder() = default;
		Builder& name(const string& name) {this->_name = name; return *this;}
		Builder& description(const string& description) {this->_description = description; return *this;}
		Builder& speed(int speed) {this->_speed = speed; return *this;}
		Builder& features(const vector<Feature>& features) {this->_features = features; return *this;}

		Race build() {return Race(this);}

		friend class Race;
	};
private:
	Race(Race::Builder* builder){
		this->name = builder->_name;
		this->description = builder->_description;
		this->speed = builder->_speed;
		this->features = builder->_features;
	}

public:
	Race() = default;
	~Race();

	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
	const int getSpeed() const {return this->speed; }
	const vector<Feature>& getFeatures() const {return this->features;}
};
