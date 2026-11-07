#include "../../../include/player/features/Feature.h"

Feature::Feature(const string& jsonPath){
    JsonDeserializer jd(Feature::SRC_DIR + jsonPath);
    this->name = jd.get<string>("name");
    this->description = jd.get<string>("description");
    this->prereq = jd.get<string>("prereq");
    for(string tag : jd.get<vector<string>>("tags")) this->tags.push_back(tag);
    this->optional = jd.get<bool>("optional");
	this->hidden = jd.get<bool>("hidden");
    this->spellcastingBlueprint = new SpellcastingBlueprint(jd.get<string>("spellcasting"));
    this->exclusiveSelect = jd.get<bool>("exclusive_selection");
    
    for(string abilityPath : jd.get<vector<string>>("base_abilities")){
        if(FileUtils::getPathType(Ability::SRC_DIR + abilityPath) == FileUtils::FILE){
            this->baseAbilities.push_back(Ability(abilityPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(Ability::SRC_DIR + abilityPath);
        for(string path : paths){
            path.erase(0, Ability::SRC_DIR.size());
            this->baseAbilities.push_back(Ability(path));
        }
    }

    for(string traitModificationPath : jd.get<vector<string>>("base_trait_modifications")){
        if(FileUtils::getPathType(TraitModification::SRC_DIR + traitModificationPath) == FileUtils::FILE){
            this->baseTraitMods.push_back(TraitModification(traitModificationPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(TraitModification::SRC_DIR + traitModificationPath);
        for(string path : paths){ 
            path.erase(0, TraitModification::SRC_DIR.size());
            this->baseTraitMods.push_back(TraitModification(path));
        }
    }

    for(string abilitySelectorPath : jd.get<vector<string>>("ability_selectors")){
        if(FileUtils::getPathType(Selector<Ability>::SRC_DIR + abilitySelectorPath) == FileUtils::FILE){
            this->abilitySelectors.push_back(Selector<Ability>(abilitySelectorPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(Selector<Ability>::SRC_DIR + abilitySelectorPath);
        for(string path : paths){
            path.erase(0, Selector<Ability>::SRC_DIR.size());
            this->abilitySelectors.push_back(Selector<Ability>(path));
        }
    }

    for(string traitModificationSelectorPath : jd.get<vector<string>>("trait_modification_selectors")){
        if(FileUtils::getPathType(Selector<TraitModification>::SRC_DIR + traitModificationSelectorPath) == FileUtils::FILE){
            this->traitModSelectors.push_back(Selector<TraitModification>(traitModificationSelectorPath));
            continue;
        }
        vector<string> paths = FileUtils::getAllFiles(Selector<TraitModification>::SRC_DIR + traitModificationSelectorPath);
        for(string path : paths){
            path.erase(0, Selector<TraitModification>::SRC_DIR.size());
            this->traitModSelectors.push_back(Selector<TraitModification>(path));
        }
    }
}

string Feature::serialize() const {
    JsonSerializer js;
    js.put("name", this->name);
    js.put("description", this->description);
    js.put("prereq", this->prereq);
    for(const string& tag : this->tags) js.addToList("tags", tag);
    js.put("optional", this->optional);
    js.put("hidden", this->hidden);
    js.put("spellcasting", this->spellcastingBlueprint->serialize());
    js.put("exclusive_selection", this->exclusiveSelect);
    
    js.createList("base_abilities");
    for(const Ability& ability : this->baseAbilities) js.addToList("base_abilities", ability.serialize());

    js.createList("base_trait_modification");
    for(const TraitModification& traitModification : this->baseTraitMods) js.addToList("base_trait_modification", traitModification.serialize());

    js.createList("ability_selectors");
    for(const Selector<Ability> abilitySelector : this->abilitySelectors) js.addToList("ability_selectors", abilitySelector.serialize());
    
    js.createList("trait_modification_selectors");
    for(const Selector<TraitModification> traitModificationSelector : this->traitModSelectors) js.addToList("trait_modification_selectors", traitModificationSelector.serialize());

    return js.str();
}
