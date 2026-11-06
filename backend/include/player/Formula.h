#pragma once
#include <vector>
#include <string>
#include <variant>

//#include "Player.h"
typedef int Player; //if Gerrit pushes this you may call him stupid one (1) time -Gerrit
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

	typedef variant<OP, KEYWORD, int> element;
	vector<element> formula;

public:
	Formula(const string& formula_str);
	int evaluate(const Player&) const;

};
