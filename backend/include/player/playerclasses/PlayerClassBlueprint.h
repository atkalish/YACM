#pragma once

#include <string>
#include <vector>
#include "../features/Ability.h"
#include "../features/TraitModification.h"
#include "../features/Selector.h"
#include "../features/Feature.h"
#include "../Item.h"
#include "../spellcasting/SpellcastingBlueprint.h"
#include "PlayerSubclass.h"
#include "../../serdes/JsonDeserializer.h"
#include "../../serdes/JsonSerializer.h"


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
    Feature classProficiencies;

    vector<vector<Item>> startingEquipment;

public:
    inline static const string SRC_DIR = "data/resources/playerclasses/playerclasses/";
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

        Feature _classProficiencies;

        vector<vector<Item>> _startingEquipment;
    public:
        Builder() = default;

        Builder& name(const string& name){this->_name = name; return *this;}
        Builder& descripiton(const string& description){this->_description = description; return *this;}
        Builder& multiClassPrereqs(const string& multiClassPrereqs){this->_multiClassPrereqs = multiClassPrereqs; return *this;}
        Builder& featureTable(vector<vector<Feature>> featureTable){this->_featureTable = featureTable; return *this;}
        Builder& hitDie(int hitDie){this->_hitDie = hitDie; return *this;}
        Builder& firstLevelHitPoints(const Formula& firstLevelHitPoints){this->_firstLevelHitPoints = firstLevelHitPoints; return *this;}
        Builder& higherlevelHitPoints(const Formula& higherlevelHitPoints){this->_higherLevelHitPoints = higherlevelHitPoints; return *this;}
        Builder& classProficiencies(const Feature& classProficiencies){this->_classProficiencies = classProficiencies; return *this;}
        Builder& subclasses(const vector<PlayerSubclass>& subclasses){this->_subclasses = subclasses; return *this;}
        Builder& subclassLevel(int subclassLevel){this->_subclassLevel = subclassLevel; return *this;}
        Builder& startingEquipment(const vector<vector<Item>>& startingEquipment){this->_startingEquipment = startingEquipment; return *this;}
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
        this->classProficiencies = builder->_classProficiencies;
        this->subclasses = builder->_subclasses;
        this->subclassLevel = builder->_subclassLevel;
        this->startingEquipment = builder->_startingEquipment;
    }

public:
    PlayerClassBlueprint(const string& jsonPath);
    PlayerClassBlueprint() = default;
    ~PlayerClassBlueprint() = default;

    string serialize() const;

    const string& getName(){return this->name;}
    const string& getDescription(){return this->description;}
    const string& getMultiClassPrereqs(){return this->multiClassPrereqs;}
    const vector<vector<Feature>>& getFeatureTable() const {return this->featureTable;}
    int getHitDie(){return this->hitDie;}
    const Formula& getFirstLevelHitPoints(){return this->firstLevelHitPoints;}
    const Formula& getHigherLevelHitPoints(){return this->higherLevelHitPoints;}
    const Feature& getClassProficiencies(){return this->classProficiencies;}
    const vector<PlayerSubclass>& getPlayerSubclasses(){return this->subclasses;}
    const vector<vector<Item>>& getStartingEquipment() const {return this->startingEquipment;}
    int getPlayerSubclassLevel(){return this->subclassLevel;}
};
