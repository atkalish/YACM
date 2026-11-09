#include "../../include/player/Player.h"

string Player::serialize() const {
    JsonSerializer js;

    JsonSerializer abilityScores_js;
    for(const pair<string, int>& pair : this->abilityScores) 
        abilityScores_js.put(pair.first, pair.second);
    js.put("ability_scores", abilityScores_js.str());

    JsonSerializer description_js;
    description_js.put("name", this->description.getName());
    description_js.put("age", this->description.getAge());
    description_js.put("height", this->description.getHeight());
    description_js.put("weight", this->description.getWeight());
    description_js.put("eyes", this->description.getEyes());
    description_js.put("skin", this->description.getEyes());
    description_js.put("hair", this->description.getHair());
    js.put("description", description_js.str());

    JsonSerializer personality_js;
    personality_js.put("alignment", this->personality.getAlignment());
    personality_js.put("traits", this->personality.getTraits());
    personality_js.put("ideals", this->personality.getIdeals());
    personality_js.put("bonds", this->personality.getBonds());
    personality_js.put("flaws", this->personality.getFlaws());
    js.put("personality", personality_js.str());

    js.put("affiliations", this->affiliations);
    js.put("backstory", this->backstory);

    js.put("race", this->race.serialize());
    js.put("background", this->race.serialize());

    js.createList("classes");
    for(const PlayerClass& playerClass : this->playerClasses)
        js.addToList("classes", playerClass.serialize());

    js.put("inspiration", this->inspiration);
    js.put("armorClass", this->armorClass);
    js.put("initiative", this->initiative);
    js.put("speed", this->speed);

    JsonSerializer hp_js;
    hp_js.put("max_hp", this->hp.getMaxHP());
    hp_js.put("current_hp", this->hp.getCurrentHP());
    hp_js.put("temp_hp", this->hp.getTempHP());
    js.put("hp", hp_js.str());

    JsonSerializer deathSaves_js;
    deathSaves_js.put("sucesses", this->deathSaves.getSuccesses());
    deathSaves_js.put("failures", this->deathSaves.getFailures());
    js.put("death_saves", deathSaves_js.str());

    JsonSerializer proficiencies_js;
    proficiencies_js.put("proficiency_bonus", this->proficiencies.getProficiencyBonus());

    proficiencies_js.createList("saving_throws");
    for(const string& prof : this->proficiencies.getSavingThrows())
        proficiencies_js.addToList("saving_throws", prof);
    
    proficiencies_js.createList("skills");
    for(const string& prof : this->proficiencies.getSkills())
        proficiencies_js.addToList("skills", prof);

    proficiencies_js.createList("misc");
    for(const string& prof : this->proficiencies.getMiscProficiencies())
        proficiencies_js.addToList("misc", prof);

    js.put("proficiencies", proficiencies_js.str());
    
    JsonSerializer money_js;
    money_js.put("copper", this->money.getCopper());
    money_js.put("silver", this->money.getSilver());
    money_js.put("electrum", this->money.getElectrum());
    money_js.put("gold", this->money.getGold());
    money_js.put("platinum", this->money.getPlatinum());
    js.put("money", money_js.str());

    js.createList("items");
    for(const Item& item : this->items)
        js.addToList("items", item.serialize());
    
    js.createList("features");
    for(const Feature& feature : this->features)
        js.addToList("features", feature.serialize());

    js.createList("spellcastings");
    for(const Spellcasting& spellcasting : this->spellcastings)
        js.addToList("spellcasting", spellcasting.serialize());

    return js.str();
}