#include "../../../include/player/playerclasses/PlayerSubclass.h"

PlayerSubclass::PlayerSubclass(const string& jsonPath){
    JsonDeserializer jd(PlayerSubclass::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");

    vector<vector<string>> featureTable = jd.get<vector<vector<string>>>("feature_table");
    for(int i = 0; i < featureTable.size(); ++i){
        vector<Feature> featurePerLevel;
        for(const string& featurePath : featureTable[i]){
            if(FileUtils::getPathType(Feature::SRC_DIR + featurePath) == FileUtils::FILE){
                featurePerLevel.push_back(Feature(featurePath));
                continue;
            }

            vector<string> paths = FileUtils::getAllFiles(Feature::SRC_DIR + featurePath);
            for(string path : paths){
                path.erase(0, Feature::SRC_DIR.size());
                featurePerLevel.push_back(Feature(path));
            }
        }
        this->featureTable.push_back(featurePerLevel);
    }
}
