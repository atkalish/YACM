#include "../../../include/player/playerclasses/PlayerClass.h"

PlayerClass::PlayerClass(const PlayerClassBlueprint& blueprint){
    this->blueprint = blueprint;
    this->level = 1;
    this->currentHitDice = 1;

    // get level 1 features
    for(const Feature& feature : blueprint.getFeatureTable()[0]){
        this->features.push_back(feature);
    }

    for(const vector<Item> equipmentOptions : blueprint.getStartingEquipment()){
        this->startingEquipment.push_back(Selector<Item>::Builder()
                                            .currentList(vector<Item>())
                                            .newList(equipmentOptions)
                                            .hookIDs(vector<string>())
                                            .minCount("1")
                                            .maxCount("1")
                                            .build());
    }
}


PlayerClass::PlayerClass(const JsonDeserializer& jd){
    this->blueprint = PlayerClassBlueprint(jd.get<JsonDeserializer>("blueprint"));
    this->level = jd.get<int>("level");
    this->currentHitDice = jd.get<int>("current_hit_dice");
    this->subclass = PlayerSubclass(jd.get<JsonDeserializer>("subclass"));
    
    for(const JsonDeserializer& feature_jd : jd.get<vector<JsonDeserializer>>("features")){
        this->features.push_back(Feature(feature_jd));
    }

    for(const JsonDeserializer& selector_jd : jd.get<vector<JsonDeserializer>>("starting_equipment")){
        this->startingEquipment.push_back(Selector<Item>(selector_jd));
    }
}

string PlayerClass::serialize() const {
    JsonSerializer js;
    js.put("blueprint", this->blueprint.serialize());
    js.put("level", this->level);
    js.put("current_hit_dice", this->currentHitDice);
    js.put("subclass", this->subclass.serialize());
    
    js.createList("features");
    for(const Feature& feature : this->features)
        js.addToList("features", feature.serialize());

    js.createList("starting_equipment");
    for(const Selector<Item>& selector : this->startingEquipment)
        js.addToList("starting_equipment", selector.serialize());

    return js.str();
}