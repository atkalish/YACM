#include "../../include/player/Formula.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <variant>

bool isDigit(const string& str) {
	for(char c : str) {
		if(!std::isdigit(static_cast<unsigned char>(c))) { return false; }
	}
	return true;
}

Formula::Formula(const string& formula_str) {
	//take a string in the format term *(+ term)
	//where a term is of the form element *(mult element)
	//where a element is number / keyword
	
	vector<string> terms = {};
	int start = 0;
	int element_start = 0;
	for(int i = 0; i < formula_str.size(); ++i) {
		if(formula_str[i] == '+' || formula_str[i] == '-' || formula_str[i] == '*' || i == formula_str.size() - 1) {
			string term = formula_str.substr(start, i - start + (int)(i == formula_str.size()-1));
			if(term[0] == '[') { term = term.substr(1, term.size() - 2); }
			terms.push_back(term);
			if(formula_str[i] == '+' || formula_str[i] == '*' || formula_str[i] == '-') terms.push_back({formula_str[i]});
			start = i + 1;
		}
	}

	this->formula.push_back(0);
	this->formula.push_back(OP::ADD);
	for(const string& term : terms) {
		if(term == "+") {this->formula.push_back(OP::ADD);}
		else if (term == "*") {this->formula.push_back(OP::MULT);}
		else if (term == "-") {this->formula.push_back(OP::SUB);}
		else if (isDigit(term)) {this->formula.push_back(atoi(term.c_str()));}
		else {
			if(Formula::hasKeyword(term)) { this->formula.push_back(Formula::stringToKeyword(term)); }
			else {this->formula.push_back(term);}
		}
	}
	cout << endl;
}

int Formula::evaluate(const Player& player) const {
	if(this->formula.size() == 0) {
		throw runtime_error("Formula has 0 elements");
	}
	if(holds_alternative<OP>(this->formula[2])) {
		throw runtime_error("Formula cannot start with operator");
	}
	if(holds_alternative<OP>(this->formula[this->formula.size() - 1])) {
		throw runtime_error("Formula cannot end with an operator");
	}

	//PLAN
	/*
	 * 1. divide into terms
	 * 2. for each term, determine if it is addition or subtraction
	 * 3. compute product over term
	 * 4. add or subtract depending on associated operator
	*/

	int i = 0;
	bool is_adding;
	int total = 0;
	int sum = 1;

	for(const element& e : this->formula) {
		if(holds_alternative<OP>(e)) {
			switch(get<OP>(e)) {
			case MULT:
				continue;
			case ADD:
				if(is_adding) total += sum;
				else total -= sum;
				sum = 1;
				is_adding = true;
				break;
			case SUB:
				if(is_adding) total += sum;
				else total -= sum;
				sum = 1;
				is_adding = false;
				break;
			}
		} else {
			sum *= Formula::getElementValue(player, e);
		}
	}

	if(is_adding) total += sum;
	else total -= sum;

	return total;
}


//key assumes that operation is not included
int Formula::getElementValue(const Player& player, const element& key) {
		if(holds_alternative<KEYWORD>(key)) { return 0; } //temporary!!!
		else if(holds_alternative<int>(key)) { return get<int>(key); }
		else if(holds_alternative<string>(key)) { return 0; } //temporary!!!
		else { throw runtime_error("How did you manage to have a different type of element in a formula??"); }
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
