#include "../../include/player/Item.h"

Item::Item(const string& jsonPath){
    JsonDeserializer jd(Item::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");
}

string Item::serialize() const {
    JsonSerializer js;
    js.put("name", this->name);
    js.put("description", this->description);
    return js.str();
}
