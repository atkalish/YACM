#include "../../include/player/Race.h"

Race::Race(const string& jsonPath){
    JsonDeserializer jd(Race::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");

    vector<string> featurePaths = jd.get<vector<string>>("features");
    for(string featurePath : featurePaths){
        if(FileUtils::getPathType(featurePath) == FileUtils::FILE){
            this->features.push_back(Feature(featurePath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(featurePath);
        for(string path : paths) this->features.push_back(Feature(path));
    }
}