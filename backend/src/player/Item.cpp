#include "../../include/player/Item.h"

Item::Item(const string& jsonPath){
    JsonDeserializer jd(Item::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");
}