#include "../../../include/player/spellcasting/Spellcasting.h"

Spellcasting::Spellcasting(const JsonDeserializer& jd){
    for(const JsonDeserializer spellWrapper_jd : jd.get<vector<JsonDeserializer>>("spell_list")){
        SpellWrapper spellWrapper;
        spellWrapper.prepared = jd.get<bool>("prepared");
        spellWrapper.spell = Spell::Builder()
            .name(spellWrapper_jd.get<string>("spell", "name"))
            .level(jd.get<int>("spell", "level"))
            .source(jd.get<string>("spell", "source"))
            .school(jd.get<string>("spell", "school"))
            .ritual(jd.get<bool>("spell", "ritual"))
            .castingTime(jd.get<string>("spell", "casting_time"))
            .range(jd.get<string>("spell", "range"))
            .components(jd.get<string>("spell", "components"))
            .duration(jd.get<string>("spell", "duration"))
            .description(jd.get<string>("spell", "description"))
            .higherLevel(jd.get<string>("spell", "higher_level"))
            .tags(jd.get<vector<string>>("spell", "tags"))
            .build();
        this->spellList.push_back(spellWrapper);
    }

    this->blueprint = SpellcastingBlueprint::Builder()
        .focus(jd.get<string>("blueprint", "focus"))
        .spellList()
        .spellSelectors()
        .ritual()
        .spellAbilityInfo()
        .spellSaveFormula()
        .spellAttackFormula()
        .spellPreparation()
        .spellsKnown()
        .spellSlots(jd.get<vector<vector<int>>>("blueprint", "spell_slots"))
        .build();
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