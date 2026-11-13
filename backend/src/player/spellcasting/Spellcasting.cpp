#include "../../../include/player/spellcasting/Spellcasting.h"

Spellcasting::Spellcasting(const JsonDeserializer& jd){
    for(const JsonDeserializer spellWrapper_jd : jd.get<vector<JsonDeserializer>>("spell_list")){
        SpellWrapper spellWrapper;
        spellWrapper.prepared = jd.get<bool>("prepared");
        spellWrapper.spell = Spell(jd.get<JsonDeserializer>("spell"));
        this->spellList.push_back(spellWrapper);
    }

    this->blueprint = SpellcastingBlueprint(jd.get<JsonDeserializer>("blueprint"));

    vector<int> spellSlots = jd.get<vector<int>>("spell_slots");
    for(int i = 0; i < spellSlots.size(); ++i) this->spellSlots[i] = spellSlots[i];
}

string Spellcasting::serialize() const {
    JsonSerializer js;
    js.put("blueprint", this->blueprint.serialize());

    js.createList("spell_list");
    for(const Spellcasting::SpellWrapper& spellWrapper : this->spellList){
        JsonSerializer spellWarpper_js;
        spellWarpper_js.put("spell", spellWrapper.spell.serialize());
        spellWarpper_js.put("prepared", spellWrapper.prepared);
        js.addToList("spell_list", spellWarpper_js.str());
    }

    js.createList("spell_slots");
    for(int i = 0; i < 9; ++i) js.addToList("spell_slots", this->spellSlots[i]);

    return js.str();
}