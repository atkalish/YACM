#pragma once
#include <string>
#include <vector>
#include <variant>
#include "Spell.h"

using namespace std;

typedef string Formula;
typedef variant<Formula, int, vector<int>> SelectionCount;

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
	SelectionCount minNumSelect; //min amount to select/replace
	SelectionCount maxNumSelect; //max amount to select/replace
	int level; //what level of spell does effect. -1 for any level.

public:
	class Builder {
	private:
		string _text;
		bool _replacesSpells;
		vector<string> _hookIDs;
		SelectionCount _minNumSelect;
		SelectionCount _maxNumSelect;
		int _level;
	public:
		Builder& text(const string& text) {this->_text = text; return *this;}
		Builder& replacesSpells(bool replacesSpells) {this->_replacesSpells = replacesSpells; return *this;}
		Builder& hookIDs(const vector<string>& hookIDs) {this->_hookIDs = hookIDs; return *this;}
		Builder& minNumSelect(const SelectionCount& minNumSelect) {this->_minNumSelect = minNumSelect; return *this;}
		Builder& maxNumSelect(const SelectionCount& maxNumSelect) {this->_maxNumSelect = maxNumSelect; return *this;}
		Builder& level(int level) {this->_level = level; return *this;}
	};


	bool hasHook(const string& hook);
	void select(vector<Spell>& current_list, const vector<Spell>& total_list);
};
