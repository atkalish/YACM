#pragma once

#include <vector>
#include <string>
#include "../spellcasting/Spellcasting.h"
#include "PlayerClassBlueprint.h"
#include "playerclasses/PlayerSubclass.h"
#include "features/TraitModification.h"

using namespace std;

class PlayerClass{
private:
    PlayerClassBlueprint blueprint;

    int level;
    int currentHitDice;
    Selector<PlayerSubclass> subclass;
    vector<Feature> features;

    Spellcasting spellcasting;

    vector<Selector<Item>> startingEquipment;

public:
    PlayerClass() = default;
    PlayerClass(PlayerClassBlueprint blueprint);
    ~PlayerClass();

    const PlayerClassBlueprint& getBlueprint() const {return this->blueprint;}
    int getLevel() const {return this->level;}
    int getCurrentHitDie() const {return this->currentHitDice;}
    const Spellcasting& getSpellcasting() const {return this->spellcasting;}
    const Selector<PlayerSubclass>& getPlayerSubclass() const {return this->subclass;}
    const vector<Feature>& getFeatures() const {return this->features;}
    const vector<Selector<Item>>& getSartingEquipment() const {return this->startingEquipment;}
};
