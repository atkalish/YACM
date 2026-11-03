#include "../../../include/player/features/Selector.h"

template<> Selector<Ability>::Selector(const string& jsonPath){
    JsonDeserializer jd(Selector::SRC_DIR + jsonPath);
    
    for(string path : jd.get<vector<string>>("super_list")){
        if(FileUtils::getPathType(path) == FileUtils::FILE){
            this->newList.push_back(Ability(path));
            continue;
        }
        vector<string> subPaths = FileUtils::getAllFiles(path);
        for(string subPath : subPaths) this->newList.push_back(Ability(subPath));
    }

    for(string hook : jd.get<vector<string>>("hooks")) this->hookIDs.push_back(hook);
    this->minCount = jd.get<string>("minimum_count");
    this->maxCount = jd.get<string>("maximum_count");
}

template<> Selector<TraitModification>::Selector(const string& jsonPath){
    JsonDeserializer jd(Selector::SRC_DIR + jsonPath);
    
    for(string path : jd.get<vector<string>>("super_list")){
        if(FileUtils::getPathType(path) == FileUtils::FILE){
            this->newList.push_back(TraitModification(path));
            continue;
        }
        vector<string> subPaths = FileUtils::getAllFiles(path);
        for(string subPath : subPaths) this->newList.push_back(TraitModification(subPath));
    }

    for(string hook : jd.get<vector<string>>("hooks")) this->hookIDs.push_back(hook);
    this->minCount = jd.get<string>("minimum_count");
    this->maxCount = jd.get<string>("maximum_count");
}
