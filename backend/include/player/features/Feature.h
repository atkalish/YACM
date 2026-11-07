#pragma once
#include "Ability.h"
#include "TraitModification.h"
#include "Selector.h"
#include "../spellcasting/Spellcasting.h"
#include "../../serdes/JsonDeserializer.h"
#include "../../serdes/JsonSerializer.h"
#include "../../Utils.h"

//Feature is *just* a wrapper for these.
class Feature {
	//concept: Feature has two types of *things*
	//  1. base<T>s --> ones that do not change across levels or hooks or whatever. For example: timeless body
	//  2. <T>Selectors --> ones that do change across hooks or levels or whatever. For example: Eldritch Invocations

private:
	vector<Ability> baseAbilities;
	vector<TraitModification> baseTraitMods;

	SpellcastingBlueprint* spellcastingBlueprint;

	bool exclusiveSelect;
	vector<Selector<Ability>> abilitySelectors; //problem: feat known as "resiliant". Current solution: let the restriction be cosmetic, i.e. we say pretty plz
	vector<Selector<TraitModification>> traitModSelectors;

	string name;
	string description;
	vector<string> tags; //DOES NOT INCLUDE HOOKS. HOOKS ARE IN SELECTORS
	string prereq;
	bool optional;
	bool hidden;

public:
	inline static const string SRC_DIR = "data/resources/features/features/";
	class Builder {
	private:
		vector<Ability> _baseAbilities;
		vector<TraitModification> _baseTraitMods;
		SpellcastingBlueprint* _spellcastingBlueprint = nullptr;

		bool _exclusiveSelect;
		vector<Selector<Ability>> _abilitySelectors; //problem: feat known as "resiliant". Current solution: let the restriction be cosmetic, i.e. we say pretty plz
		vector<Selector<TraitModification>> _traitModSelectors;

		string _name;
		string _description;
		vector<string> _tags; //DOES NOT INCLUDE HOOKS. HOOKS ARE IN SELECTORS
		string _prereq;
		bool _optional;
		bool _hidden;
	public:
		Builder() = default;
		Builder& baseAbilities(const vector<Ability>& baseAbilities) {this->_baseAbilities = baseAbilities; return *this;}
		Builder& baseTraitModifications(const vector<TraitModification>& baseTraitMods) {this->_baseTraitMods = baseTraitMods; return *this;}
		Builder& spellcasting(SpellcastingBlueprint* spellcastingBlueprint) {this->_spellcastingBlueprint = spellcastingBlueprint; return *this;}
		Builder& exclusiveSelect(bool exclusiveSelect) {this->_exclusiveSelect = exclusiveSelect; return *this;}
		Builder& abilitySelectors(const vector<Selector<Ability>>& abilitySelectors) {this->_abilitySelectors = abilitySelectors; return *this;}
		Builder& traitModSelectors(const vector<Selector<TraitModification>>& traitModSelectors) {this->_traitModSelectors = traitModSelectors; return *this;}
		Builder& name(const string& name) {this->_name = name; return *this;}
		Builder& description(const string& description) {this->_description = description; return *this;}
		Builder& tags(const vector<string>& tags) {this->_tags = tags; return *this;}
		Builder& prereq(const string& prereq) {this->_prereq = prereq; return *this;}
		Builder& optional(bool optional) {this->_optional = optional; return *this;}
		Builder& hidden(bool hidden) {this->_hidden = hidden; return *this;}
		
		Feature build() {return Feature(this);}
		friend class Feature;
	};
private:
	Feature(const Builder* builder) {
		this->baseAbilities = builder->_baseAbilities;
		this->baseTraitMods = builder->_baseTraitMods;
		this->spellcastingBlueprint = builder->_spellcastingBlueprint;
		this->exclusiveSelect = builder->_exclusiveSelect;
		this->abilitySelectors = builder->_abilitySelectors;
		this->traitModSelectors = builder->_traitModSelectors;
		this->name = builder->_name;
		this->description = builder->_description;
		this->tags = builder->_tags;
		this->prereq = builder->_prereq;
		this->optional = builder->_optional;
		this->hidden = builder->_hidden;
	}
public:
	const vector<Ability>& getBaseAbilities() const {return this->baseAbilities;}
	const vector<TraitModification>& getBaseTraitMods() const {return this->baseTraitMods;}
	bool getExclusiveSelect() const {return this->exclusiveSelect;}
	const vector<Selector<Ability>>& getAbilitySelectors() const {return this->abilitySelectors;}
	const vector<Selector<TraitModification>>& getTraitModSelectors() const {return this->traitModSelectors;}
	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
	const vector<string>& getTags() const {return this->tags;}
	const string& getPrereq() const {return this->prereq;}
	const vector<Spellcasting>& getSpellCastings() const;
	bool getOptional() const {return this->optional;}
	bool getHidden() const {return this->hidden;}

	Feature() = default;
	Feature(const string& jsonPath);
	~Feature() = default;

	string serialize() const;
};
