#pragma once

#include <vector>
#include <string>
#include "spellcasting/Spellcasting.h"
#include "PlayerClassBlueprint.h"
#include "playerclasses/PlayerSubclass.h"
#include "abilities/TraitModification.h"

using namespace std;

class PlayerClass{
private:
    PlayerClassBlueprint blueprint;

    int level;
    int currentHitDice;
    Selector<PlayerSubclass> subclass;
    Selector<TraitModification> _armorProficiencies;
    Selector<TraitModification> _weaponProficiencies;
    Selector<TraitModification> _toolProficiencies;
    Selector<TraitModification> _savingThrowProficiencies;
    Selector<TraitModification> _skillProficiencies;
    vector<Item> _equipmentProficiencies;

    Spellcasting spellcasting;

public:
    PlayerClass() = default;
    PlayerClass(PlayerClassBlueprint blueprint);
    ~PlayerClass();

    const PlayerClassBlueprint& getBlueprint() const {return this->blueprint;}
    int getLevel() const {return this->level;}
    int getCurrentHitDie() const {return this->currentHitDice;}
    const Spellcasting& getSpellcasting() const {return this->spellcasting;}
    const Selector<PlayerSubclass>& getSubclass() const {return this->subclass;}
};