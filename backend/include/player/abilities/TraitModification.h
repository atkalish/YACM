#pragma once
#include <string>

using namespace std;
typedef string Formula;

class TraitModification {
private:
	string targetID;
	Formula formula;
public:
	TraitModification() = default;
	~TraitModification();
};
