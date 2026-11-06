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

string Feature::serialize() const {
    JsonSerializer js;
    js.put("name", this->name);
    js.put("description", this->description);
    js.put("prereq", this->prereq);
    for(const string& tag : this->tags) js.addToList("tags", tag);
    js.put("optional", this->optional);
    js.put("hidden", this->hidden);
    js.put("spellcasting", this->spellcastingBlueprint->serialize());
    js.put("exclusive_select", this->exclusiveSelect);
    
    for(const Ability& ability : this->baseAbilities) js.addToList("base_abilities", ability.serialize());
    for(const TraitModification& traitModification : this->baseTraitMods) js.addToList("base_trait_modification", traitModification.serialize());
    for(const Selector<Ability> abilitySelector : this->abilitySelectors) js.addToList("ability_selectors", abilitySelector.serialize());
    for(const Selector<TraitModification> traitModificationSelector : this->traitModSelectors) js.addToList("trait_modification_selectors", traitModificationSelector.serialize());

    return js.str();
}
