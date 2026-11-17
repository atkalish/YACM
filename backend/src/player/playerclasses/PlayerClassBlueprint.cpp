#include "../../../include/player/playerclasses/PlayerClassBlueprint.h"

PlayerClassBlueprint::PlayerClassBlueprint(const string& jsonPath){
    JsonDeserializer jd(PlayerClassBlueprint::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");
    this->multiClassPrereqs = jd.get<string>("multi_class_prereqs");

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

    this->hitDie = jd.get<int>("hit_die");
    this->firstLevelHitPoints = jd.get<Formula>("first_level_hit_points");
    this->higherLevelHitPoints = jd.get<Formula>("higher_level_hit_points");

    for(const string& subclassPath : jd.get<vector<string>>("subclasses")){
        if(FileUtils::getPathType(PlayerSubclass::SRC_DIR + subclassPath) == FileUtils::FILE){
            this->subclasses.push_back(PlayerSubclass(subclassPath));
            continue;
        }

        vector<string> paths = FileUtils::getAllFiles(PlayerSubclass::SRC_DIR + subclassPath);
        for(string path : paths){
            path.erase(0, PlayerSubclass::SRC_DIR.size());
            this->subclasses.push_back(PlayerSubclass(subclassPath));
        }
    }

    this->subclassLevel = jd.get<int>("subclass_level");
    this->classProficiencies = Feature(jd.get<string>("class_proficiencies"));

    vector<vector<string>> startingEquipment = jd.get<vector<vector<string>>>("starting_equipment");
    for(int i = 0; i < startingEquipment.size(); ++i){
        vector<Item> equipmentOptions;
        for(const string& equipmentPath : startingEquipment[i]){
            if(FileUtils::getPathType(Item::SRC_DIR + equipmentPath) == FileUtils::FILE){
                equipmentOptions.push_back(Item(equipmentPath));
                continue;
            }

            vector<string> paths = FileUtils::getAllFiles(Item::SRC_DIR + equipmentPath);
            for(string path : paths){
                path.erase(0, Item::SRC_DIR.size());
                equipmentOptions.push_back(Item(path));
            }
        }
        this->startingEquipment.push_back(equipmentOptions);
    }
}

PlayerClassBlueprint::PlayerClassBlueprint(const JsonDeserializer& jd){
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");
    this->multiClassPrereqs = jd.get<string>("multi_class_prereqs");

    for(const vector<JsonDeserializer>& jds : jd.get<vector<vector<JsonDeserializer>>>("feature_table")){
        vector<Feature> features;
        for(const JsonDeserializer& feature_jd : jds) features.push_back(Feature(feature_jd));
        this->featureTable.push_back(features);
    }

    this->hitDie = jd.get<int>("hit_die");
    this->firstLevelHitPoints = jd.get<Formula>("first_level_hit_points");
    this->higherLevelHitPoints = jd.get<Formula>("higher_level_hit_points");

    for(const JsonDeserializer& subclasses_jd : jd.get<vector<JsonDeserializer>>("subclasses")){
        this->subclasses.push_back(PlayerSubclass(subclasses_jd));
    }

    this->subclassLevel = jd.get<int>("subclass_level");
    this->classProficiencies = Feature(jd.get<JsonDeserializer>("class_proficiencies"));

    for(const vector<JsonDeserializer>& jds : jd.get<vector<vector<JsonDeserializer>>>("starting_equipment")){    
        vector<Item> items;
        for(const JsonDeserializer& item_jd : jds) 
            items.push_back(Item::Builder()
                .name(item_jd.get<string>("name"))
                .description(item_jd.get<string>("description"))
                .build()
            );
        this->startingEquipment.push_back(items);
    }
}

string PlayerClassBlueprint::serialize() const {
    JsonSerializer js;
    js.put("name", this->name);
    js.put("description", this->description);
    js.put("multi_class_prereqs", this->multiClassPrereqs);
    
    js.createTable("feature_table", this->featureTable.size());
    for(int i = 0; i < this->featureTable.size(); ++i){
        for(const Feature& feature : this->featureTable[i]){
            string test = feature.serialize();
            js.addToTable("feature_table", i, feature.serialize());
        }
    }
    js.put("hit_die", this->hitDie);
    js.put("first_level_hit_points", this->firstLevelHitPoints);
    js.put("higher_level_hit_points", this->higherLevelHitPoints);
    
    js.createList("subclasses");
    for(const PlayerSubclass& playerSubclass : this->subclasses) js.addToList("subclasses", playerSubclass.serialize());

    js.put("subclass_level", this->subclassLevel);
    js.put("class_proficiencies", this->classProficiencies.serialize());

    js.createTable("starting_equipment", this->startingEquipment.size());
    for(int i = 0; i < this->startingEquipment.size(); ++i){
        for(const Item& item : this->startingEquipment[i]){
            js.addToTable("starting_equipment", i, item.serialize());
        }
    }
    return js.str();
}