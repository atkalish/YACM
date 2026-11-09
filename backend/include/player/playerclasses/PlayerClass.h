#pragma once

#include <vector>
#include <string>
#include "../spellcasting/Spellcasting.h"
#include "PlayerClassBlueprint.h"
#include "PlayerSubclass.h"
#include "../features/TraitModification.h"
#include "../../serdes/JsonSerializer.h"

using namespace std;

class PlayerClass{
private:
    PlayerClassBlueprint blueprint;

    int level;
    int currentHitDice;
    PlayerSubclass subclass;
    vector<Feature> features;
    vector<Selector<Item>> startingEquipment;

public:
    PlayerClass() = default;
    PlayerClass(const PlayerClassBlueprint& blueprint);
    ~PlayerClass() = default;

    string serialize() const;

    const PlayerClassBlueprint& getBlueprint() const {return this->blueprint;}
    int getLevel() const {return this->level;}
    int getCurrentHitDie() const {return this->currentHitDice;}
    const PlayerSubclass& getPlayerSubclass() const {return this->subclass;}
    const vector<Feature>& getFeatures() const {return this->features;}
    const vector<Selector<Item>>& getStartingEquipment() const {return this->startingEquipment;}
};
