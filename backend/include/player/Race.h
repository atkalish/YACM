#pragma once
#include "features/Feature.h"
#include "features/TraitModification.h"
#include "features/Selector.h"
#include "../serdes/JsonDeserializer.h"

class Race {
private:
	inline static const string SRC_DIR = "data/resources/races/";
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
		Builder& name(const string& name) {this->_name = name; return *this;}
		Builder& description(const string& description) {this->_description = description; return *this;}
		Builder& features(const vector<Feature>& features) {this->_features = features; return *this;}

		Race build() {return Race(this);}

		friend class Race;
	};
private:
	Race(Race::Builder* builder){
		this->name = builder->_name;
		this->description = builder->_description;
		this->features = builder->_features;
	}

public:
	Race() = default;
	Race(const string& jsonPath);
	~Race() = default;

	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
	const vector<Feature>& getFeatures() const {return this->features;}
};
