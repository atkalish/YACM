#include "../../../include/player/features/TraitModification.h"

TraitModification::TraitModification(const string& jsonPath) {
	JsonDeserializer jd(TraitModification::SRC_DIR + jsonPath);
	this->targetID = jd.get<string>("target_id");
	this->formula = jd.get<string>("formula");
}
