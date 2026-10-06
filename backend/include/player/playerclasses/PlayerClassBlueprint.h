#pragma once

#include <string>
#include <vector>
#include "abilities/Ability.h"
#include "abilities/TraitModification.h"
#include "abilities/Selector.h"
#include <Item.h>
#include "spellcasting/SpellcastingBlueprint.h"
#include "abilities/Feature.h"
#include "playerclasses/PlayerSubclass.h"



typedef string Formula;
using namespace std;


class PlayerClassBlueprint{
private:
    string name;
    string description;
    string multiClassPrereqs;
    vector<vector<Feature>> featureTable;
    int hitDie;
    Formula firstLevelHitPoints;
    Formula higherLevelHitPoints;

    vector<PlayerSubclass> subclasses;
    int subclassLevel;

    // proficiencies
    vector<string> armorProficiencies;
    vector<string> weaponProficiencies;
    vector<string> toolProficiencies;
    vector<string> savingThrowProficiencies;
    vector<string> skillProficiencies;
    vector<Item> equipmentProficiencies;

    // how many you can choose from the list
    int armorProficiencyCount;
    int weaponProficiencyCount;
    int toolProficiencyCount;
    int savingThrowProficiencyCount;
    int skillProficiencyCount;
    int equipmentProficiencyCount;

    SpellcastingBlueprint spellCastingBlueprint;

public:
    class Builder{
    private:
        string _name;
        string _description;
        string _multiClassPrereqs;
        vector<vector<Feature>> _featureTable;
        int _hitDie;
        Formula _firstLevelHitPoints;
        Formula _higherLevelHitPoints;

        vector<PlayerSubclass> _subclasses;
        int _subclassLevel;

        vector<string> _armorProficiencies;
        vector<string> _weaponProficiencies;
        vector<string> _toolProficiencies;
        vector<string> _savingThrowProficiencies;
        vector<string> _skillProficiencies;
        vector<Item> _equipmentProficiencies;
        SpellcastingBlueprint _spellCastingBlueprint;

        int _armorProficiencyCount;
        int _weaponProficiencyCount;
        int _toolProficiencyCount;
        int _savingThrowProficiencyCount;
        int _skillProficiencyCount;
        int _equipmentProficiencyCount;

    public:
        Builder() = default;

        Builder& name(const string& name){this->_name = name; return *this;}
        Builder& descripiton(const string& description){this->_description = description; return *this;}
        Builder& multiClassPrereqs(const string& multiClassPrereqs){this->_multiClassPrereqs = multiClassPrereqs; return *this;}
        Builder& featureTable(vector<vector<Feature>> featureTable){this->_featureTable = featureTable; return *this;}
        Builder& hitDie(int hitDie){this->_hitDie = hitDie; return *this;}
        Builder& firstLevelHitPoints(const Formula& firstLevelHitPoints){this->_firstLevelHitPoints = firstLevelHitPoints; return *this;}
        Builder& higherlevelHitPoints(const Formula& higherlevelHitPoints){this->_higherLevelHitPoints = higherlevelHitPoints; return *this;}
        Builder& armorProficiencies(const vector<string>& armorProficiencies){this->_armorProficiencies = armorProficiencies; return *this;}
        Builder& weaponProficiencies(const vector<string>& weaponProficiencies){this->_weaponProficiencies = weaponProficiencies; return *this;}
        Builder& toolProficiencies(const vector<string>& toolProficiencies){this->_toolProficiencies = toolProficiencies; return *this;}
        Builder& savingThrowProficiencies(const vector<string>& savingThrowProficiencies){this->_savingThrowProficiencies = savingThrowProficiencies; return *this;}
        Builder& skillProficiencies(const vector<string>& skillProficiencies){this->_skillProficiencies = skillProficiencies; return *this;}
        Builder& equipmentProficiencies(const vector<Item>& equipmentProficiencies){this->_equipmentProficiencies = equipmentProficiencies; return *this;}
        Builder& spellcastingBlueprint(const SpellcastingBlueprint& spellcastingBlueprint){this->_spellCastingBlueprint = spellcastingBlueprint; return *this;}
        Builder& subclasses(const vector<PlayerSubclass>& subclasses){this->_subclasses = subclasses; return *this;}
        Builder& subclassLevel(int subclassLevel){this->_subclassLevel = subclassLevel; return *this;}
        Builder& armorProficiencyCount(int armorProficiencyCount){this->_armorProficiencyCount = armorProficiencyCount; return *this;}
        Builder& weaponProficiencyCount(int weaponProficiencyCount){this->_weaponProficiencyCount = weaponProficiencyCount; return *this;}
        Builder& toolProficiencyCount(int toolProficiencyCount){this->_toolProficiencyCount = toolProficiencyCount; return *this;}
        Builder& savingThrowProficiencyCount(int savingThrowProficiencyCount){this->_savingThrowProficiencyCount = savingThrowProficiencyCount; return *this;}
        Builder& skillProficiencyCount(int skillProficiencyCount){this->_skillProficiencyCount = skillProficiencyCount; return *this;}
        Builder& equipmentProficiencyCount(int equipmentProficiencyCount){this->_equipmentProficiencyCount = equipmentProficiencyCount; return *this;}
        PlayerClassBlueprint build(){return PlayerClassBlueprint(this);}
        friend class PlayerClassBlueprint;
    };

private:
    PlayerClassBlueprint(PlayerClassBlueprint::Builder* builder){
        this->name = builder->_name;
        this->description = builder->_description;
        this->multiClassPrereqs = builder->_multiClassPrereqs;
        this->featureTable = builder->_featureTable;
        this->hitDie = builder->_hitDie;
        this->firstLevelHitPoints = builder->_firstLevelHitPoints;
        this->higherLevelHitPoints = builder->_higherLevelHitPoints;
        this->armorProficiencies = builder->_armorProficiencies;
        this->weaponProficiencies = builder->_weaponProficiencies;
        this->toolProficiencies = builder->_toolProficiencies;
        this->savingThrowProficiencies = builder->_savingThrowProficiencies;
        this->skillProficiencies = builder->_skillProficiencies;
        this->equipmentProficiencies = builder->_equipmentProficiencies;
        this->spellCastingBlueprint = builder->_spellCastingBlueprint;
        this->subclasses = builder->_subclasses;
        this->subclassLevel = builder->_subclassLevel;
        this->armorProficiencyCount = builder->_armorProficiencyCount;
        this->weaponProficiencyCount = builder->_weaponProficiencyCount;
        this->toolProficiencyCount = builder->_toolProficiencyCount;
        this->savingThrowProficiencyCount = builder->_savingThrowProficiencyCount;
        this->skillProficiencyCount = builder->_skillProficiencyCount;
        this->equipmentProficiencyCount = builder->_equipmentProficiencyCount;
    }

public:
    PlayerClassBlueprint() = default;
    ~PlayerClassBlueprint();

    const string& getName(){return this->name;}
    const string& getDescription(){return this->description;}
    const string& getMultiClassPrereqs(){return this->multiClassPrereqs;}
    const vector<vector<Feature>>& getAbilityTable(){return this->featureTable;}
    int getHitDie(){return this->hitDie;}
    const Formula& getFirstLevelHitPoints(){return this->firstLevelHitPoints;}
    const Formula& getHigherLevelHitPoints(){return this->higherLevelHitPoints;}
    const vector<string>& getArmorProficiencies(){return this->armorProficiencies;}
    const vector<string>& getWeaponProficiencies(){return this->weaponProficiencies;}
    const vector<string>& getToolProficiency(){return this->toolProficiencies;}
    const vector<string>& getSavingThrowProficiencies(){return this->savingThrowProficiencies;}
    const vector<string>& getSkillProficiencies(){return this->skillProficiencies;}
    const vector<Item>& getEquipmentProficiencies(){return this->equipmentProficiencies;}
    const SpellcastingBlueprint getSpellCastingBlueprint(){return this->spellCastingBlueprint;}
    const vector<PlayerSubclass>& getPlayerSubclasses(){return this->subclasses;}
    int getPlayerSubclassLevel(){return this->subclassLevel;}
    int getArmorProficiencyCount(){return this->armorProficiencyCount;}
    int getweaponProficiencyCount(){return this->weaponProficiencyCount;}
    int getToolProficiencyCount(){return this->toolProficiencyCount;}
    int getSavingThrowsProficiencyCount(){return this->savingThrowProficiencyCount;}
    int getSkillProficiencyCount(){return this->skillProficiencyCount;}
    int getEquipmentProficiencyCount(){return this->equipmentProficiencyCount;}
};