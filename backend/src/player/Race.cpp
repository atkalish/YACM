#include "../../include/player/Race.h"

Race::Race(const string& jsonPath){
    JsonDeserializer jd(Race::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");

    for(string featurePath : jd.get<vector<string>>("features")){
        if(FileUtils::getPathType(Feature::SRC_DIR + featurePath) == FileUtils::FILE){
            this->features.push_back(Feature(featurePath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(Feature::SRC_DIR + featurePath);
        for(string path : paths){
            path.erase(0, Feature::SRC_DIR.size());
            this->features.push_back(Feature(path));
        }
    }
}

string Race::serialize() const {
    JsonSerializer js;
    js.put("name", this->name);
    js.put("description", this->description);

    for(const Feature& feature : this->features) js.addToList("features", feature.serialize());

    return js.str();
}