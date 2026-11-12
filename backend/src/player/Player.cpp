#include "../../include/player/Player.h"

Player::Player(const string& jsonPath){
    JsonDeserializer jd(Player::SRC_DIR + jsonPath);
    
    //description
    this->description = Player::Description::Builder()
        .name(jd.get<string>("description", "name"))
        .age(jd.get<string>("description", "age"))
        .height(jd.get<string>("description", "height"))
        .weight(jd.get<string>("description", "weight"))
        .eyes(jd.get<string>("description", "eyes"))
        .skin(jd.get<string>("description", "skin"))
        .hair(jd.get<string>("description", "hair"))
        .build();

    this->personality = Player::Personality::Builder()
        .alignment(jd.get<string>("personality", "alignment"))
        .traits(jd.get<string>("personality", "traits"))
        .ideals(jd.get<string>("personality", "ideals"))
        .bonds(jd.get<string>("personality", "bonds"))
        .flaws(jd.get<string>("personality", "flaws"))
        .build();

    this->hp = HitPoints(
        jd.get<int>("hp", "max_hp"),
        jd.get<int>("hp", "current_hp"),
        jd.get<int>("hp", "temp_hp")
    );

    this->deathSaves.setSuccesses(jd.get<int>("death_saves", "successes"));
    this->deathSaves.setFailures(jd.get<int>("death_saves", "failures"));

    this->proficiencies.proficiencyBonus = jd.get<int>("proficiencies", "proficiency_bonus");
    
    for(string savingThrow : jd.get<vector<string>>("proficiencies", "saving_throws"))
        this->proficiencies.addSavingThrowProficiency(savingThrow);

    for(string skill : jd.get<vector<string>>("proficiencies", "skills"))
        this->proficiencies.addSkillProficiency(skill);

    for(string misc : jd.get<vector<string>>("proficiencies", "misc"))
        this->proficiencies.addMiscProficiency(misc);

    this->money.setCopper(jd.get<int>("money", "copper"));
    this->money.setSilver(jd.get<int>("money", "silver"));
    this->money.setElectrum(jd.get<int>("money", "electrum"));
    this->money.setGold(jd.get<int>("money", "gold"));
    this->money.setPlatinum(jd.get<int>("money", "platinum"));

    this->abilityScores["charisma"] = jd.get<int>("ability_scores", "charisma");
    this->abilityScores["constitution"] = jd.get<int>("ability_scores", "constitution");
    this->abilityScores["dexterity"] = jd.get<int>("ability_scores", "dexterity");
    this->abilityScores["intelligence"] = jd.get<int>("ability_scores", "intelligence");
    this->abilityScores["strength"] = jd.get<int>("ability_scores", "strength");
    this->abilityScores["wisdom"] = jd.get<int>("ability_scores", "wisdom");

    this->affiliations = jd.get<string>("affiliations");
    this->backstory = jd.get<string>("backstory");

    vector<Feature> raceFeatures;
    for(const JsonDeserializer& feature_jd : jd.get<vector<JsonDeserializer>>("race", "features"))
        raceFeatures.push_back(Feature(feature_jd));
    this->race = Race::Builder()
        .name(jd.get<string>("race", "name"))
        .description(jd.get<string>("race", "description"))
        .features(raceFeatures)
        .build();

    
    vector<Item> backgroundEquipment;
    for(const JsonDeserializer& item_jd : jd.get<vector<JsonDeserializer>>("equipment", "features")){
        backgroundEquipment.push_back(Item::Builder()
            .name(item_jd.get<string>("name"))
            .description(item_jd.get<string>("description"))    
            .build()
        );
    }

    vector<Feature> backgroundFeatures;
    for(const JsonDeserializer& feature_jd : jd.get<vector<JsonDeserializer>>("background", "features"))
        raceFeatures.push_back(Feature(feature_jd));
    this->background = Background::Builder()
        .name(jd.get<string>("background", "name"))
        .description(jd.get<string>("background", "name"))
        .suggestedCharacteristics(jd.get<string>("background", "suggested_characteristics"))
        .equipment(backgroundEquipment)
        .features(backgroundFeatures)
        .build();

    for(const JsonDeserializer& playerClass_jd : jd.get<vector<JsonDeserializer>>("classes"))
        this->playerClasses.push_back(PlayerClass(playerClass_jd));

    this->inspiration = jd.get<int>("inspiration");
    this->armorClass = jd.get<int>("armor_class");
    this->initiative = jd.get<int>("initiative");
    this->speed = jd.get<int>("speed");

    for(const JsonDeserializer& item_jd : jd.get<vector<JsonDeserializer>>("items")){
        this->items.push_back(Item::Builder()
            .name(item_jd.get<string>("name"))
            .description(item_jd.get<string>("description"))
            .build()
        );
    }

    for(const JsonDeserializer& spellcasting_jd : jd.get<vector<JsonDeserializer>>("spellcastings"))
        this->spellcastings.push_back(Spellcasting(spellcasting_jd));
}

string Player::serialize() const
{
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
    js.put("armor_class", this->armorClass);
    js.put("initiative", this->initiative);
    js.put("speed", this->speed);

    JsonSerializer hp_js;
    hp_js.put("max_hp", this->hp.getMaxHP());
    hp_js.put("current_hp", this->hp.getCurrentHP());
    hp_js.put("temp_hp", this->hp.getTempHP());
    js.put("hp", hp_js.str());

    JsonSerializer deathSaves_js;
    deathSaves_js.put("successes", this->deathSaves.getSuccesses());
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

    js.createList("spellcastings");
    for(const Spellcasting& spellcasting : this->spellcastings)
        js.addToList("spellcasting", spellcasting.serialize());

    return js.str();
}