#pragma once
#include <string>
#include "../../serdes/JsonDeserializer.h"

using namespace std;
typedef string Formula;

class TraitModification {
private:
	inline static const string SRC_DIR = "data/resources/features/traitmodifications/";
	string targetID;
	Formula formula;
public:
	const string& getTargetID() const {return this->targetID;}
	const Formula& getFormula() const {return this->formula;}

	TraitModification(const string& targetID, const Formula& formula) : targetID(targetID), formula(formula) {}
	TraitModification(const string& jsonPath);
	TraitModification() = default;
	~TraitModification() = default;
};
