#include "../../../include/player/spellcasting/SpellSelector.h"

SpellSelector::SpellSelector(const string& jsonPath){
    JsonDeserializer jd(SpellSelector::SRC_DIR + jsonPath);

    this->text = jd.get<string>("description");
    this->replacesSpells = jd.get<bool>("replaces_spells");
    this->hookIDs = jd.get<vector<string>>("hooks");
    this->minNumSelect = jd.get<string>("min_selection");
    this->maxNumSelect = jd.get<string>("max_selection");
    this->levelObtained = jd.get<int>("level_obtained");
    this->level = jd.get<int>("level");
}