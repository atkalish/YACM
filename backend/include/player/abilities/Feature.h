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
	vector<Ability>baseAbilities;
	vector<TraitModification> baseTraits;

	bool exclusiveSelect;
	vector<Selector<Ability>> abilitySelectors; //problem: feat known as "resiliant". Current solution: let the restriction be cosmetic, i.e. we say pretty plz
	vector<Selector<TraitModification>> traitSelectors;
	//SpellSelector; <-- this is WIP for later. consider examples where you pull from multiple classes' lists, and that you need a live reference to a list

	string name;
	vector<string> tags; //DOES NOT INCLUDE HOOKS. HOOKS ARE IN SELECTORS
	string prereq;
	bool optional;

public:
	void enactHook(const string& hook);
};
