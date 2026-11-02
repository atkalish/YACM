#include "../../../include/player/features/Feature.h"

Feature::Feature(const string& jsonPath){
    JsonDeserializer jd(Feature::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("name");
    this->prereq = jd.get<string>("prereq");
    for(string tag : jd.get<vector<string>>("tags")) this->tags.push_back(tag);
    this->optional = jd.get<bool>("optional");
    this->spellcastingBlueprint = new SpellcastingBlueprint(jd.get<string>("spellcasting"));
    this->exclusiveSelect = jd.get<bool>("exclusive_select");
    
    for(string abilityPath : jd.get<vector<string>>("base_abilities")){
        if(FileUtils::getPathType(abilityPath) == FileUtils::FILE){
            this->baseAbilities.push_back(Ability(abilityPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(abilityPath);
        for(string path : paths) this->baseAbilities.push_back(Ability(path));
    }

    for(string traitModificationPath : jd.get<vector<string>>("base_trait_modifications")){
        if(FileUtils::getPathType(traitModificationPath) == FileUtils::FILE){
            this->baseTraitMods.push_back(TraitModification(traitModificationPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(traitModificationPath);
        for(string path : paths) this->baseTraitMods.push_back(TraitModification(path));
    }

    for(string abilitySelectorPath : jd.get<vector<string>>("ability_selectors")){
        if(FileUtils::getPathType(abilitySelectorPath) == FileUtils::FILE){
            this->abilitySelectors.push_back(Selector<Ability>(abilitySelectorPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(abilitySelectorPath);
        for(string path : paths) this->abilitySelectors.push_back(Selector<Ability>(path));
    }

    for(string traitModificationSelectorPath : jd.get<vector<string>>("trait_modification_selectors")){
        if(FileUtils::getPathType(traitModificationSelectorPath) == FileUtils::FILE){
            this->traitModSelectors.push_back(Selector<TraitModification>(traitModificationSelectorPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(traitModificationSelectorPath);
        for(string path : paths) this->traitModSelectors.push_back(Selector<TraitModification>(path));
    }
}


