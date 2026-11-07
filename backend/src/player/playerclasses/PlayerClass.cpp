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
        this->startingEquipment.push_back(Selector<Item>::Builder().
                                            currentList(vector<Item>()).
                                            newList(equipmentOptions).
                                            hookIDs(vector<string>()).
                                            minCount("1").
                                            maxCount("1").
                                            build());
    }
}