#include "../../../include/player/spellcasting/SpellcastingBlueprint.h"

SpellcastingBlueprint::SpellcastingBlueprint(const string& jsonPath){
    JsonDeserializer jd(SpellcastingBlueprint::SRC_DIR + jsonPath);
    this->focus = jd.get<string>("focus");
    
    for(string spellListPath : jd.get<vector<string>>("spell_lists")){
        JsonDeserializer spellListJD(SpellcastingBlueprint::SPELL_LIST_SRC_DIR + spellListPath);
        for(string spellPath : spellListJD.get<vector<string>>("spells")){
            if(FileUtils::getPathType(spellPath) == FileUtils::FILE){
                this->spellList.push_back(Spell(spellPath));
                continue;
            }
            vector<string> paths = FileUtils::getAllFiles(spellPath);
            for(string path : paths) this->spellList.push_back(Spell(path));
        }
    }

    for(string spellSelectorPath : jd.get<vector<string>>("spell_selectors")){
        if(FileUtils::getPathType(spellSelectorPath) == FileUtils::FILE){
                this->spellSelectors.push_back(SpellSelector(spellSelectorPath));
                continue;
            }
            vector<string> paths = FileUtils::getAllFiles(spellSelectorPath);
            for(string path : paths) this->spellSelectors.push_back(SpellSelector(path));
    }

    this->ritual = jd.get<bool>("ritual");
    this->spellAbilityInfo = jd.get<string>("spell_ability_info");
    this->spellSaveFormula = jd.get<string>("spell_attack_formula");
    this->spellAttackFormula = jd.get<string>("spell_attack_formula");
    this->spellPreparation = jd.get<string>("spell_preparation");
    this->spellsKnown = jd.get<string>("spells_known");

    for(vector<int> spellLevelSlots : jd.get<vector<vector<int>>>("spell_slost")) this->spellSlots.push_back(spellLevelSlots);
}