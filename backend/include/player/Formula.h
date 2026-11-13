#pragma once
#include <map>
#include <vector>
#include <string>
#include <variant>

//#include "Player.h"
typedef int Player; //if Gerrit pushes this [to main] you may call him stupid one (1) time -Gerrit
using namespace std;

class Formula {
private:
	enum KEYWORD {
		LEVEL,
		PROF,
		SPEED,
		PP,
		GP,
		EP,
		SP,
		CP,
		STR,
		DEX,
		CON,
		INT,
		WIS,
		CHAR,
		STR_SCORE,
		DEX_SCORE,
		CON_SCORE,
		INT_SCORE,
		WIS_SCORE,
		CHAR_SCORE,
		STR_SAVE,
		DEX_SAVE,
		CON_SAVE,
		INT_SAVE,
		WIS_SAVE,
		CHAR_SAVE,
		ACROBATICS,
		ANIMAL_HANDLING,
		ARCANA,
		ATHLETICS,
		DECEPTION,
		HISTORY,
		INSIGHT,
		INTIMIDATION,
		INVESTIGATION,
		MEDICINE,
		NATURE,
		PERCEPTION,
		PERFORMANCE,
		PERSUASION,
		RELIGION,
		SLIGHT_OF_HAND,
		STEALTH,
		SURVIVAL
	};
	enum OP {
		ADD,
		SUB,
		MULT
	};





	typedef variant<OP, KEYWORD, int, string> element;
	vector<element> formula;

	static int getElementValue(const Player& player, const element& key);
	static const string& keywordToString(KEYWORD k);
	static KEYWORD stringToKeyword(const string& s);
	static bool hasKeyword(const string& s);

public:
	Formula(const string& formula_str);
	string toString() const;
	int evaluate(const Player&) const;
};
