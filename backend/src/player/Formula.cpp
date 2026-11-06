#include "../../include/player/Formula.h"
#include <iostream>

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
}
