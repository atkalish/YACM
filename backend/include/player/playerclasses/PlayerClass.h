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
    Selector<TraitModification> armorProficiencies;
    Selector<TraitModification> weaponProficiencies;
    Selector<TraitModification> toolProficiencies;
    Selector<TraitModification> savingThrowProficiencies;
    Selector<TraitModification> skillProficiencies;
    Selector<Item> equipmentProficiencies;

    Spellcasting spellcasting;

public:
    PlayerClass() = default;
    PlayerClass(PlayerClassBlueprint blueprint);
    ~PlayerClass();

    const PlayerClassBlueprint& getBlueprint() const {return this->blueprint;}
    int getLevel() const {return this->level;}
    int getCurrentHitDie() const {return this->currentHitDice;}
    const Spellcasting& getSpellcasting() const {return this->spellcasting;}
    const Selector<PlayerSubclass>& getPlayerSubclass() const {return this->subclass;}
    const Selector<TraitModification>& getArmorProficiencies() const {return this->armorProficiencies;}
    const Selector<TraitModification>& getweaponProficiencies() const {return this->weaponProficiencies;}
    const Selector<TraitModification>& getToolProficiencies() const {return this->toolProficiencies;}
    const Selector<TraitModification>& getSavingThrowProficiencies() const {return this->savingThrowProficiencies;}
    const Selector<TraitModification>& getSkillProficiencies() const {return this->skillProficiencies;}
    const Selector<Item>& getItemProficiencies() const {return this->equipmentProficiencies;}
};
