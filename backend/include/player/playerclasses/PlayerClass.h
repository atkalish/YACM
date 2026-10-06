#pragma once

#include <vector>
#include <string>
#include "../spellcasting/Spellcasting.h"
#include "PlayerClassBlueprint.h"

using namespace std;

class PlayerClass{
private:
    PlayerClassBlueprint blueprint;

    int level;
    int currentHitDice;

    Spellcasting spellcasting;

public:
    PlayerClass() = default;
    PlayerClass(PlayerClassBlueprint blueprint);
    ~PlayerClass();

    const PlayerClassBlueprint& getBlueprint() const {return this->blueprint;}
    int getLevel() const {return this->level;}
    int getCurrentHitDie() const {return this->currentHitDice;}
    const Spellcasting& getSpellcasting() const {return this->spellcasting;}
};
