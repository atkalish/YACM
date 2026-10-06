#pragma once
#include <string>

using namespace std;
typedef string Formula;

class TraitModification {
private:
	string targetID;
	Formula formula;
public:
	const string& getTargetID() const {return this->targetID;}
	const Formula& getFormula() const {return this->formula;}

	TraitModification(const string& targetID, const Formula& formula) : targetID(targetID), formula(formula) {}
	~TraitModification();
};
