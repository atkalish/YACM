#pragma once
#include <string>
#include <vector>
#include "Spell.h"
#include "SpellSelector.h"

using namespace std;
typedef string Formula;

class SpellcastingBlueprint{
private:
    string focus;
    vector<Spell> spellList;
    vector<SpellSelector> spellSelectors;
    bool ritual;
    string spellAbilityInfo;
    Formula spellSaveFormula;
    Formula spellAttackFormula;
    string spellPreparation;

    // may only be applicable for class spellcasting
    string spellsKnown;
    int spellSlots[20][10]; // 20 levels, 10 spell level (including cantrips)

public:
    class Builder {
    private:
        string _focus;
        vector<Spell> _spellList;
        vector<SpellSelector> _spellSelectors;
        bool _ritual;
        string _spellAbilityInfo;
        Formula _spellAttackFormula;
        Formula _spellSaveFormula;
        string _spellPreparation;

    public:
        Builder() = default;

        Builder& focus(const string& focus){this->_focus = focus; return *this;}
        Builder& spellList(const vector<Spell> spellList){this->_spellList = spellList; return *this;}
        Builder& spellSelector(const vector<SpellSelector> spellSelectors){this->_spellSelectors= spellSelectors; return *this;}
        Builder& ritual(bool ritual){this->_ritual = ritual; return *this;}
        Builder& spellcastingAbilty(const string& spellAbiltyInfo){this->_spellAbilityInfo = spellAbiltyInfo; return *this;}
        Builder& spellAttackFormula(const Formula& spellAttackFormula){this->_spellAttackFormula = spellAttackFormula; return *this;}
        Builder& spellSaveFormula(const Formula& spellSaveFormula){this->_spellSaveFormula = spellSaveFormula; return *this;}
        Builder& spellPreparation(const string& spellPreparation){this->_spellPreparation = spellPreparation; return *this;}
        SpellcastingBlueprint build(){return SpellcastingBlueprint(this);}
        friend class SpellcastingBlueprint;
    };

private:
    SpellcastingBlueprint(SpellcastingBlueprint::Builder* builder){
        this->focus = builder->_focus;
        this->spellList = builder->_spellList;
        this->ritual = builder->_ritual;
        this->spellAbilityInfo = builder->_spellAbilityInfo;
        this->spellAttackFormula = builder->_spellAttackFormula;
        this->spellSaveFormula = builder->_spellAttackFormula;
        this->spellPreparation = builder->_spellPreparation;
    }

public:
    SpellcastingBlueprint() = default;

    const string& getFocus(){return this->focus;}
    const vector<Spell>& getSpellList(){return this->spellList;};
    bool isRitual(){return this->ritual;}
    const string& getSpellAbility(){return this->spellAbilityInfo;}
    const string& getSpellPreparation(){return this->spellPreparation;}
};
