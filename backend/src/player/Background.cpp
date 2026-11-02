#include "../../include/player/Background.h"

Background::Background(const string& jsonPath){
    JsonDeserializer jd(Background::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");
    
    vector<string> equipmentPaths = jd.get<vector<string>>("equipment");
    for(string equipmentPath : equipmentPaths){
        if(FileUtils::getPathType(equipmentPath) == FileUtils::FILE){
            this->equipment.push_back(Item(equipmentPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(equipmentPath);
        for(string path : paths) this->equipment.push_back(Item(path));
    }

    vector<string> featurePaths = jd.get<vector<string>>("features");
    for(string featurePath : featurePaths){
        if(FileUtils::getPathType(featurePath) == FileUtils::FILE){
            this->features.push_back(Feature(featurePath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(featurePath);
        for(string path : paths) this->features.push_back(Feature(path));
    }
    
    this->suggestedCharacteristics = jd.get<string>("suggested_characteristics");
}