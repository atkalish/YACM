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

string Spell::serialize() const {
    JsonSerializer js;
    js.put("name", this->name);
    js.put("description", this->description);
    js.put("level", this->level);
    js.put("source", this->source);
    js.put("school", this->school);
    js.put("ritual", this->ritual);
    js.put("casting_time", this->castingTime);
    js.put("range", this->range);
    js.put("components", this->components);
    js.put("duration", this->duration);
    js.put("higher_levels", this->higherLevel);
    for(const string& tag : this->tags) js.addToList("tags", tag);

    return js.str();
}
