#pragma once
#include "Ability.h"
#include "TraitModification.h"
#include "Selector.h"

//Feature is *just* a wrapper for these.
class Feature {
	//concept: Feature has two types of *things*
	//  1. base<T>s --> ones that do not change across levels or hooks or whatever. For example: timeless body
	//  2. <T>Selectors --> ones that do change across hooks or levels or whatever. For example: Eldritch Invocations

private:
	vector<Ability> baseAbilities;
	vector<TraitModification> baseTraitMods;

	bool exclusiveSelect;
	vector<Selector<Ability>> abilitySelectors; //problem: feat known as "resiliant". Current solution: let the restriction be cosmetic, i.e. we say pretty plz
	vector<Selector<TraitModification>> traitModSelectors;
	//SpellSelector; <-- this is WIP for later. consider examples where you pull from multiple classes' lists, and that you need a live reference to a list

	string name;
	vector<string> tags; //DOES NOT INCLUDE HOOKS. HOOKS ARE IN SELECTORS
	string prereq;
	bool optional;

public:
	class Builder {
	private:
		vector<Ability> _baseAbilities;
		vector<TraitModification> _baseTraitMods;

		bool _exclusiveSelect;
		vector<Selector<Ability>> _abilitySelectors; //problem: feat known as "resiliant". Current solution: let the restriction be cosmetic, i.e. we say pretty plz
		vector<Selector<TraitModification>> _traitModSelectors;
		//SpellSelector; <-- this is WIP for later. consider examples where you pull from multiple classes' lists, and that you need a live reference to a list

		string _name;
		vector<string> _tags; //DOES NOT INCLUDE HOOKS. HOOKS ARE IN SELECTORS
		string _prereq;
		bool _optional;
	public:
		Builder() = default;
		Builder& baseAbilities(const vector<Ability>& baseAbilities) {this->_baseAbilities = baseAbilities; return *this;}
		Builder& baseTraitModifications(const vector<TraitModification>& baseTraitMods) {this->_baseTraitMods = baseTraitMods; return *this;}
		Builder& exclusiveSelect(bool exclusiveSelect) {this->_exclusiveSelect = exclusiveSelect; return *this;}
		Builder& abilitySelectors(const vector<Selector<Ability>>& abilitySelectors) {this->_abilitySelectors = abilitySelectors; return *this;}
		Builder& traitModSelectors(const vector<Selector<TraitModification>>& traitModSelectors) {this->_traitModSelectors = traitModSelectors; return *this;}
		Builder& name(const string& name) {this->_name = name; return *this;}
		Builder& tags(const vector<string>& tags) {this->_tags = tags; return *this;}
		Builder& prereq(const string& prereq) {this->_prereq = prereq; return *this;}
		Builder& optional(bool optional) {this->_optional = optional; return *this;}
		
		Feature build() {return Feature(this);}
		friend class Feature;
	};
};
