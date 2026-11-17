#include "../../../include/player/features/TraitModification.h"

TraitModification::TraitModification(const string& jsonPath){
    JsonDeserializer jd(TraitModification::SRC_DIR + jsonPath);
    *this = TraitModification(jd);
}

TraitModification::TraitModification(const JsonDeserializer& jd){
    this->targetID = jd.get<string>("target_id");
    this->formula = jd.get<string>("formula");
}

string TraitModification::serialize() const {
    JsonSerializer js;
    js.put("target_id", this->targetID);
    js.put("formula", this->formula);
    return js.str();
}
