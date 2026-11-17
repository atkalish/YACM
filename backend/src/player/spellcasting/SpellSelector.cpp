#include "../../../include/player/spellcasting/SpellSelector.h"

SpellSelector::SpellSelector(const string& jsonPath){
    JsonDeserializer jd(SpellSelector::SRC_DIR + jsonPath);

    this->text = jd.get<string>("description");
    this->replacesSpells = jd.get<bool>("replaces_spells");
    this->hookIDs = jd.get<vector<string>>("hooks");
    this->minNumSelect = jd.get<Formula>("min_selection");
    this->maxNumSelect = jd.get<Formula>("max_selection");
    this->levelObtained = jd.get<int>("level_obtained");
    this->level = jd.get<int>("level");
}

string SpellSelector::serialize() const {
    JsonSerializer js;
    js.put("description", this->text);
    js.put("replaces_spells", this->replacesSpells);
    for(const string& hook : this->hookIDs) js.addToList("hooks", hook);
    js.put("min_selection", this->minNumSelect);
    js.put("max_selection", this->maxNumSelect);
    js.put("level_obtained", this->levelObtained);
    js.put("level", this->level);

    return js.str();
}
