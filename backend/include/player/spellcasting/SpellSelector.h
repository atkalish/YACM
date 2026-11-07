#pragma once
#include <string>
#include <vector>
#include <variant>
#include "Spell.h"
#include "../../serdes/JsonDeserializer.h"
#include "../../serdes/JsonSerializer.h"
#include "../../Utils.h"

using namespace std;

typedef string Formula;

class SpellSelector {
	/*
	 * This class is functionally a behavior.
	 * on a hook, take in a current spell list and total spell list,
	 * and select/replace [formula] spells of level [formula]
	*/

private:
	string text; //this is kinda a feature, and as such will have associated text
	bool replacesSpells; //whether or not to replace (alternative select)
	vector<string> hookIDs; //lv up, short rest,long rest, etc etc
	Formula minNumSelect; //min amount to select/replace
	Formula maxNumSelect; //max amount to select/replace
	int levelObtained; //what level does the player obtain this
	int level; //what level of spell does effect. -1 for any level.

public:
	inline static const string SRC_DIR = "data/resources/spellcasting/spellselectors/";
	class Builder {
	private:
		string _text;
		bool _replacesSpells;
		vector<string> _hookIDs;
		Formula _minNumSelect;
		Formula _maxNumSelect;
		int _levelObtained;
		int _level;
	public:
		Builder& text(const string& text) {this->_text = text; return *this;}
		Builder& replacesSpells(bool replacesSpells) {this->_replacesSpells = replacesSpells; return *this;}
		Builder& hookIDs(const vector<string>& hookIDs) {this->_hookIDs = hookIDs; return *this;}
		Builder& minNumSelect(const Formula& minNumSelect) {this->_minNumSelect = minNumSelect; return *this;}
		Builder& maxNumSelect(const Formula& maxNumSelect) {this->_maxNumSelect = maxNumSelect; return *this;}
		Builder& levelObtained(int level) {this->_levelObtained = level; return *this;}
		Builder& level(int level) {this->_level = level; return *this;}
		SpellSelector build() {return SpellSelector(this);}
	friend class SpellSelector;
	};

private:
	SpellSelector(Builder* builder) {
		this->text = builder->_text;
		this->replacesSpells = builder->_replacesSpells;
		this->hookIDs = builder->_hookIDs;
		this->minNumSelect = builder->_minNumSelect;
		this->maxNumSelect = builder->_maxNumSelect;
		this->levelObtained = builder->_levelObtained;
		this->level = builder->_level;
	}
public:
	SpellSelector() = default;
	SpellSelector(const string& jsonPath);

	string serialize() const;
	bool hasHook(const string& hook);
	void select(vector<Spell>& current_list, const vector<Spell>& total_list);
};
