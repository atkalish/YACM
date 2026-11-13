#include "../../include/player/Formula.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <variant>

Formula::Formula(const string& formula_str) {
	//take a string in the format term *(+ term)
	//where a term is of the form element *(mult element)
	//where a element is number / keyword
	
	vector<string> terms = {};
	int start = 0;
	int element_start = 0;
	for(int i = 0; i < formula_str.size(); ++i) {
		if(formula_str[i] == '+' || formula_str[i] == '-' || formula_str[i] == '*' || i == formula_str.size() - 1) {
			cout << "index: " << i << " has " << formula_str[i] << ", start: " << start << " has " << formula_str[start] << std::endl;
			string term = formula_str.substr(start, i - start + (int)(i == formula_str.size()-1));
			terms.push_back(term);
			if(formula_str[i] == '+' || formula_str[i] == '*' || formula_str[i] == '-') terms.push_back({formula_str[i]});
			start = i + 1;
		}
	}

	for(const string& term : terms) {
		//PARSE TERM INTO TERMS
	}
string Formula::toString() const {
	string s = "";
	for(const element& e : this->formula) {
		if(holds_alternative<string>(e)) s += "{" + get<string>(e) + "}";
		else if(holds_alternative<int>(e)) s += to_string(get<int>(e));
		else if(holds_alternative<KEYWORD>(e)) s += "[" + Formula::keywordToString(get<KEYWORD>(e)) + "]";
		else if(holds_alternative<OP>(e)) {
			switch (get<OP>(e)) {
			case ADD: 
				s += "+";
				break;
			case SUB:
				s += "-";
				break;
			case MULT:
				s += "*";
				break;
			}
		}
	}
	return s;
}


const string& Formula::keywordToString(KEYWORD k) {
	static const map<KEYWORD, string> KEYWORD_TO_STRING{
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

	return KEYWORD_TO_STRING.find(k)->second;
}

bool Formula::hasKeyword(const string& s) {
	//I'm really tired and will deal with the consequences
	//of this action later. -Gerrit
	static const map<string, KEYWORD> STR_TO_KEYWORD{
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


	return STR_TO_KEYWORD.find(s) != STR_TO_KEYWORD.end();
}

Formula::KEYWORD Formula::stringToKeyword(const string& s) {
		static const map<string, KEYWORD> STR_TO_KEYWORD{
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
	return STR_TO_KEYWORD.find(s)->second;
}
