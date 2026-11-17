#include "../../../include/player/spellcasting/SpellcastingBlueprint.h"

SpellcastingBlueprint::SpellcastingBlueprint(const string& jsonPath){
    JsonDeserializer jd(SpellcastingBlueprint::SRC_DIR + jsonPath);
    this->focus = jd.get<string>("focus");
    
    for(string spellListPath : jd.get<vector<string>>("spell_lists")){
        JsonDeserializer spellListJD(SpellcastingBlueprint::SPELL_LIST_SRC_DIR + spellListPath);
        for(string spellPath : spellListJD.get<vector<string>>("spells")){
            if(FileUtils::getPathType(Spell::SRC_DIR + spellPath) == FileUtils::FILE){
                this->spellList.push_back(Spell(spellPath));
                continue;
            }
            vector<string> paths = FileUtils::getAllFiles(Spell::SRC_DIR + spellPath);
            for(string path : paths){
                path.erase(0, Spell::SRC_DIR.size());
                this->spellList.push_back(Spell(path));
            }
        }
    }

    for(string spellSelectorPath : jd.get<vector<string>>("spell_selectors")){
        if(FileUtils::getPathType(SpellSelector::SRC_DIR + spellSelectorPath) == FileUtils::FILE){
            this->spellSelectors.push_back(SpellSelector(spellSelectorPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(SpellSelector::SRC_DIR + spellSelectorPath);
        for(string path : paths){
            path.erase(0, SpellSelector::SRC_DIR.size());
            this->spellSelectors.push_back(SpellSelector(path));
        }
    }

    this->ritual = jd.get<bool>("ritual");
    this->spellAbilityInfo = jd.get<string>("spell_ability_info");
    this->spellSaveFormula = jd.get<string>("spell_attack_formula");
    this->spellAttackFormula = jd.get<string>("spell_attack_formula");
    this->spellPreparation = jd.get<string>("spell_preparation");
    this->spellsKnown = jd.get<string>("spells_known");

    for(vector<int> spellLevelSlots : jd.get<vector<vector<int>>>("spell_slots")) this->spellSlots.push_back(spellLevelSlots);
}

SpellcastingBlueprint::SpellcastingBlueprint(const JsonDeserializer& jd){

    for(const JsonDeserializer spell_jd : jd.get<vector<JsonDeserializer>>("spell_list")){
        this->spellList.push_back(Spell(spell_jd));
    }

    for(const JsonDeserializer spellSelector_jd : jd.get<vector<JsonDeserializer>>("spell_selectors")){
        this->spellSelectors.push_back(SpellSelector::Builder()
            .text(spellSelector_jd.get<string>("description"))
            .replacesSpells(spellSelector_jd.get<bool>("replaces_spells"))
            .hookIDs(spellSelector_jd.get<vector<string>>("hooks"))
            .minNumSelect(spellSelector_jd.get<Formula>("min_selection"))
            .maxNumSelect(spellSelector_jd.get<Formula>("max_selection"))
            .levelObtained(spellSelector_jd.get<int>("level_obtained"))
            .level(spellSelector_jd.get<int>("level"))
            .build());
    }

    this->focus = jd.get<string>("focus");
    this->ritual = jd.get<bool>("ritual");
    this->spellAbilityInfo = jd.get<string>("spell_ability_info");
    this->spellSaveFormula = jd.get<string>("spell_attack_formula");
    this->spellAttackFormula = jd.get<string>("spell_attack_formula");
    this->spellPreparation = jd.get<string>("spell_preparation");
    this->spellsKnown = jd.get<string>("spells_known");
    
    for(vector<int> spellLevelSlots : jd.get<vector<vector<int>>>("spell_slots")) this->spellSlots.push_back(spellLevelSlots);
}

string SpellcastingBlueprint::serialize() const {
    JsonSerializer js;
    js.put("focus", this->focus);

    js.createList("spell_list");
    for(const Spell& spell : this->spellList) js.addToList("spell_list", spell.serialize());

    js.createList("spell_selectors");
    for(const SpellSelector& spellSelector : this->spellSelectors) js.addToList("spell_selectors", spellSelector.serialize());
    
    js.put("ritual", this->ritual);
    js.put("spell_ability_info", this->spellAbilityInfo);
    js.put("spell_save_formula", this->spellSaveFormula);
    js.put("spell_attack_formula", this->spellAttackFormula);
    js.put("spell_preparation", this->spellPreparation);
    js.put("spells_known", this->spellsKnown);
    js.put("spell_slots", this->spellSlots);

    return js.str();
}
