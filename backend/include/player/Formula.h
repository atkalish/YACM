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

	static inline const map<string, KEYWORD> STR_TO_KEYWORD{
		{"LEVEL", LEVEL},
		{"PROF", PROF},
		{"SPEED", SPEED},
		{"PP", PP},
		{"GP", GP},
		{"EP", EP},
		{"SP", SP},
		{"CP", CP},
		{"STR", STR},
		{"DEX", DEX},
		{"CON", CON},
		{"INT", INT},
		{"WIS", WIS},
		{"CHAR", CHAR},
		{"STR_SCORE", STR_SCORE},
		{"DEX_SCORE", DEX_SCORE},
		{"CON_SCORE", CON_SCORE},
		{"INT_SCORE", INT_SCORE},
		{"WIS_SCORE", WIS_SCORE},
		{"CHAR_SCORE", CHAR_SAVE},
		{"STR_SAVE", STR_SAVE},
		{"DEX_SAVE", DEX_SAVE},
		{"CON_SAVE", CON_SAVE},
		{"INT_SAVE", INT_SAVE},
		{"WIS_SAVE", WIS_SAVE},
		{"CHAR_SAVE", CHAR_SAVE},
		{"ACROBATICS", ACROBATICS},
		{"ANIMAL_HANDLING", ANIMAL_HANDLING},
		{"ARCANA", ARCANA},
		{"ATHLETICS", ATHLETICS},
		{"DECEPTION", DECEPTION},
		{"HISTORY", HISTORY},
		{"INSIGHT", INSIGHT},
		{"INTIMIDATION", INTIMIDATION},
		{"INVESTIGATION", INVESTIGATION},
		{"MEDICINE", MEDICINE},
		{"NATURE", NATURE},
		{"PERCEPTION", PERCEPTION},
		{"PERFORMANCE", PERFORMANCE},
		{"PERSUASION", PERSUASION},
		{"RELIGION", RELIGION},
		{"SLIGHT_OF_HAND", SLIGHT_OF_HAND},
		{"STEALTH", STEALTH},
		{"SURVIVAL", SURVIVAL}
	};

	static inline const map<KEYWORD, string> KEYWORD_TO_STRING{
		{LEVEL, "LEVEL"},
		{PROF, "PROF"},
		{SPEED, "SPEED"},
		{PP, "PP"},
		{GP, "GP"},
		{EP, "EP"},
		{SP, "SP"},
		{CP, "CP"},
		{STR, "STR"},
		{DEX, "DEX"},
		{CON, "CON"},
		{INT, "INT"},
		{WIS, "WIS"},
		{CHAR, "CHAR"},
		{STR_SCORE, "STR_SCORE"},
		{DEX_SCORE, "DEX_SCORE"},
		{CON_SCORE, "CON_SCORE"},
		{INT_SCORE, "INT_SCORE"},
		{WIS_SCORE, "WIS_SCORE"},
		{CHAR_SCORE, "CHAR_SAVE"},
		{STR_SAVE, "STR_SAVE"},
		{DEX_SAVE, "DEX_SAVE"},
		{CON_SAVE, "CON_SAVE"},
		{INT_SAVE, "INT_SAVE"},
		{WIS_SAVE, "WIS_SAVE"},
		{CHAR_SAVE, "CHAR_SAVE"},
		{ACROBATICS, "ACROBATICS"},
		{ANIMAL_HANDLING, "ANIMAL_HANDLING"},
		{ARCANA, "ARCANA"},
		{ATHLETICS, "ATHLETICS"},
		{DECEPTION, "DECEPTION"},
		{HISTORY, "HISTORY"},
		{INSIGHT, "INSIGHT"},
		{INTIMIDATION, "INTIMIDATION"},
		{INVESTIGATION, "INVESTIGATION"},
		{MEDICINE, "MEDICINE"},
		{NATURE, "NATURE"},
		{PERCEPTION, "PERCEPTION"},
		{PERFORMANCE, "PERFORMANCE"},
		{PERSUASION, "PERSUASION"},
		{RELIGION, "RELIGION"},
		{SLIGHT_OF_HAND, "SLIGHT_OF_HAND"},
		{STEALTH, "STEALTH"},
		{SURVIVAL, "SURVIVAL"}
	};

	typedef variant<OP, KEYWORD, int, string> element;
	vector<element> formula;

	static int getElementValue(const Player& player, const element& key);

public:
	Formula(const string& formula_str);
	int evaluate(const Player&) const;
};
