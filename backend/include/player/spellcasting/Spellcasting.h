#pragma once

#include <string>
#include <vector>
#include "SpellcastingBlueprint.h"
#include "../../serdes/JsonDeserializer.h"

using namespace std;

class Spellcasting{
private:
    struct SpellWrapper{
        bool prepared;
        Spell spell;
    };
    SpellcastingBlueprint blueprint;
    vector<SpellWrapper> spellList;
    int spellSlots[9];
    
public:
    Spellcasting(const SpellcastingBlueprint& blueprint);
    Spellcasting(const JsonDeserializer& jd);

    string serialize() const;

    const vector<Spell>& getPreparedSpells() const;
    const vector<Spell>& getUnpreparedSpells() const;
    void addSpell(const Spell& spell, bool prepared);
    void prepareSpell(const Spell& spell);

    const SpellcastingBlueprint& getBlueprint() const {return this->blueprint;}
};