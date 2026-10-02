#pragma once
#include "abilities/Ability.h"
#include "abilities/TraitModification.h"
#include "abilities/Selector.h"

class Race {
private:
	string name;
	int speed;
	string description;
	Selector<TraitModification> languages;
	Selector<TraitModification> proficiencies;
	vector<Ability*> abilities;

public:
	class Builder {
	private:
		string _name;
		string _description;
		int _speed;
		Selector<TraitModification> _languages;
		Selector<TraitModification> _proficiencies;
		vector<Ability*> _abilities;
	public:
		Builder() = default;
		Builder& name(const string& name) {this->_name = name; return *this;}
		Builder& description(const string& description) {this->_description = description; return *this;}
		Builder& speed(int speed) {this->_speed = speed; return *this;}
		Builder& abilities(const vector<Ability*>& abilities) {this->_abilities = abilities; return *this;}

		Builder& languages(const Selector<TraitModification>& languages) {this->_languages = languages; return *this;}
		Builder& abilities(const Selector<TraitModification>& proficiencies) {this->_proficiencies = proficiencies; return *this;}

		Race build() {return Race(this);}

		friend class Race;
	};
private:
	Race(Race::Builder* builder){
		this->name = builder->_name;
		this->description = builder->_description;
		this->speed = builder->_speed;
		this->languages = builder->_languages;
		this->proficiencies = builder->_proficiencies;
		this->abilities = builder->_abilities;
	}

public:
	Race() = default;
	~Race();

	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
	const int getSpeed() const {return this->speed; }
	const vector<Ability*>& getAbilities() const {return this->abilities;};
	const Selector<TraitModification>& getLanguages() const {return this->languages;}
	const Selector<TraitModification>& getProficiencies() const {return this->proficiencies;}
};
