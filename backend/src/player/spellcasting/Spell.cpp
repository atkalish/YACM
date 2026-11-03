#include "../../../include/player/spellcasting/Spell.h"

Spell::Spell(const string& jsonPath){
    JsonDeserializer jd(Spell::SRC_DIR + jsonPath);

    this->name = jd.get<string>("name");
    this->level = jd.get<int>("level");
    this->source = jd.get<string>("source");
    this->school = jd.get<string>("school");
    this->ritual = jd.get<bool>("ritual");
    this->castingTime = jd.get<string>("casting_time");
    this->range = jd.get<string>("range");
    this->components = jd.get<string>("components");
    this->duration = jd.get<string>("duration");
    this->higherLevel = jd.get<string>("higher_levels");
    this->tags = jd.get<vector<string>>("tags");
}