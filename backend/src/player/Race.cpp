#include "../../include/player/Race.h"

Race::Race(const string& jsonPath){
    JsonDeserializer jd(Race::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");

    vector<string> featurePaths;
    for(string featurePath : featurePaths){
        
    }
}