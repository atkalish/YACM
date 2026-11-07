#include "../../../include/player/features/Selector.h"

template <> Selector<Ability>::Selector(const string &jsonPath){
    JsonDeserializer jd(Selector::SRC_DIR + jsonPath);
    
    for(string path : jd.get<vector<string>>("super_list")){
        if(FileUtils::getPathType(Ability::SRC_DIR + path) == FileUtils::FILE){
            this->newList.push_back(Ability(path));
            continue;
        }
        vector<string> subPaths = FileUtils::getAllFiles(Ability::SRC_DIR + path);
        for(string subPath : subPaths) {
            subPath.erase(0, Ability::SRC_DIR.size());
            this->newList.push_back(Ability(subPath));
        }
    }

    for(string hook : jd.get<vector<string>>("hooks")) this->hookIDs.push_back(hook);
    this->minCount = jd.get<Formula>("minimum_count");
    this->maxCount = jd.get<Formula>("maximum_count");
}

template<> Selector<TraitModification>::Selector(const string& jsonPath){
    JsonDeserializer jd(Selector::SRC_DIR + jsonPath);

    for(string path : jd.get<vector<string>>("super_list")){
        if(FileUtils::getPathType(TraitModification::SRC_DIR + path) == FileUtils::FILE){
            this->newList.push_back(TraitModification(path));
            continue;
        }
        vector<string> subPaths = FileUtils::getAllFiles(TraitModification::SRC_DIR + path);
        for(string subPath : subPaths){
            subPath.erase(0, TraitModification::SRC_DIR.size());
            this->newList.push_back(TraitModification(subPath));
        }
    }

    for(string hook : jd.get<vector<string>>("hooks")) this->hookIDs.push_back(hook);
    this->minCount = jd.get<Formula>("minimum_count");
    this->maxCount = jd.get<Formula>("maximum_count");
}

template<> string Selector<Ability>::serialize() const {
    JsonSerializer js;
    js.put("type", "ability");
    for(const Ability& ability : this->newList) js.addToList("super_list", ability.serialize());
    for(const string& hook : this->hookIDs) js.addToList("hooks", hook);
    js.put("minimum_count", this->minCount);
    js.put("maximum_count", this->maxCount);
    return js.str();
}

template<> string Selector<TraitModification>::serialize() const {
    JsonSerializer js;
    js.put("type", "trait_modification");
    for(const TraitModification& traitModification : this->newList) js.addToList("super_list", traitModification.serialize());
    for(const string& hook : this->hookIDs) js.addToList("hooks", hook);
    js.put("minimum_count", this->minCount);
    js.put("maximum_count", this->maxCount);
    return js.str();
}