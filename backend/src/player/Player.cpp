#include "../../include/player/Player.h"

Player::Player(const string& jsonPath){
    JsonDeserializer jd(Player::SRC_DIR + jsonPath);
    
    //description
    this->description = Player::Description::Builder()
        .name(jd.get<string>(Player::DESCRIPTION, Player::Description::NAME))
        .age(jd.get<string>(Player::DESCRIPTION, Player::Description::AGE))
        .height(jd.get<string>(Player::DESCRIPTION, Player::Description::HEIGHT))
        .weight(jd.get<string>(Player::DESCRIPTION, Player::Description::WEIGHT))
        .eyes(jd.get<string>(Player::DESCRIPTION, Player::Description::EYES))
        .skin(jd.get<string>(Player::DESCRIPTION, Player::Description::SKIN))
        .hair(jd.get<string>(Player::DESCRIPTION, Player::Description::HAIR))
        .build();

    this->personality = Player::Personality::Builder()
        .alignment(jd.get<string>(Player::PERSONALITY, Player::Personality::ALIGNMENT))
        .traits(jd.get<string>(Player::PERSONALITY, Player::Personality::TRAITS))
        .ideals(jd.get<string>(Player::PERSONALITY, Player::Personality::IDEALS))
        .bonds(jd.get<string>(Player::PERSONALITY, Player::Personality::BONDS))
        .flaws(jd.get<string>(Player::PERSONALITY, Player::Personality::FLAWS))
        .build();

    this->hp = HitPoints(
        jd.get<int>(Player::HP, Player::HitPoints::MAX_HP),
        jd.get<int>(Player::HP, Player::HitPoints::CURRENT_HP),
        jd.get<int>(Player::HP, Player::HitPoints::TEMP_HP)
    );

    this->deathSaves.setSuccesses(jd.get<int>(Player::DEATH_SAVES, Player::DeathSaves::SUCCESSES));
    this->deathSaves.setFailures(jd.get<int>(Player::DEATH_SAVES, Player::DeathSaves::FAILURES));

    this->proficiencies.proficiencyBonus = jd.get<int>(Player::PROFICIENCIES, Player::Proficiencies::PROFICIENCY_BONUS);
    
    for(string savingThrow : jd.get<vector<string>>(Player::PROFICIENCIES, Player::Proficiencies::SAVING_THROWS))
        this->proficiencies.addSavingThrowProficiency(savingThrow);

    for(string skill : jd.get<vector<string>>(Player::PROFICIENCIES, Player::SKILLS))
        this->proficiencies.addSkillProficiency(skill);

    for(string misc : jd.get<vector<string>>(Player::PROFICIENCIES, Player::Proficiencies::MISC))
        this->proficiencies.addMiscProficiency(misc);

    this->money.setCopper(jd.get<int>(Player::MONEY, Player::Money::COPPER));
    this->money.setSilver(jd.get<int>(Player::MONEY, Player::Money::SILVER));
    this->money.setElectrum(jd.get<int>(Player::MONEY, Player::Money::ELECTRUM));
    this->money.setGold(jd.get<int>(Player::MONEY, Player::Money::GOLD));
    this->money.setPlatinum(jd.get<int>(Player::MONEY, Player::Money::PLATINUM));

    this->abilityScores["charisma"] = jd.get<int>(Player::ABILITY_SCORES, "charisma");
    this->abilityScores["constitution"] = jd.get<int>(Player::ABILITY_SCORES, "constitution");
    this->abilityScores["dexterity"] = jd.get<int>(Player::ABILITY_SCORES, "dexterity");
    this->abilityScores["intelligence"] = jd.get<int>(Player::ABILITY_SCORES, "intelligence");
    this->abilityScores["strength"] = jd.get<int>(Player::ABILITY_SCORES, "strength");
    this->abilityScores["wisdom"] = jd.get<int>(Player::ABILITY_SCORES, "wisdom");

    this->skills["acrobatics"] = jd.get<string>(Player::SKILLS, "acrobatics");
    this->skills["animal_handling"] = jd.get<string>(Player::SKILLS, "animal_handling");
    this->skills["arcana"] = jd.get<string>(Player::SKILLS, "arcana");
    this->skills["athletics"] = jd.get<string>(Player::SKILLS, "athletics");
    this->skills["deception"] = jd.get<string>(Player::SKILLS, "deception");
    this->skills["history"] = jd.get<string>(Player::SKILLS, "history");
    this->skills["insight"] = jd.get<string>(Player::SKILLS, "insight");
    this->skills["intimidation"] = jd.get<string>(Player::SKILLS, "intimidation");
    this->skills["investigation"] = jd.get<string>(Player::SKILLS, "investigation");
    this->skills["medicine"] = jd.get<string>(Player::SKILLS, "medicine");
    this->skills["nature"] = jd.get<string>(Player::SKILLS, "nature");
    this->skills["perception"] = jd.get<string>(Player::SKILLS, "perception");
    this->skills["performance"] = jd.get<string>(Player::SKILLS, "performance");
    this->skills["persuasion"] = jd.get<string>(Player::SKILLS, "persuasion");
    this->skills["religion"] = jd.get<string>(Player::SKILLS, "religion");
    this->skills["sleight_of_hand"] = jd.get<string>(Player::SKILLS, "sleight_of_hand");
    this->skills["stealth"] = jd.get<string>(Player::SKILLS, "stealth");
    this->skills["survival"] = jd.get<string>(Player::SKILLS, "survival");

    this->affiliations = jd.get<string>(Player::AFFILIATIONS);
    this->backstory = jd.get<string>(Player::BACKSTORY);

    vector<Feature> raceFeatures;
    for(const JsonDeserializer& feature_jd : jd.get<vector<JsonDeserializer>>(Player::RACE, "features"))
        raceFeatures.push_back(Feature(feature_jd));
    this->race = Race::Builder()
        .name(jd.get<string>(Player::RACE, "name"))
        .description(jd.get<string>(Player::RACE, "description"))
        .features(raceFeatures)
        .build();

    
    vector<Item> backgroundEquipment;
    for(const JsonDeserializer& item_jd : jd.get<vector<JsonDeserializer>>(Player::BACKGROUND, "equipment")){
        backgroundEquipment.push_back(Item::Builder()
            .name(item_jd.get<string>("name"))
            .description(item_jd.get<string>("description"))    
            .build()
        );
    }
    vector<Feature> backgroundFeatures;
    for(const JsonDeserializer& feature_jd : jd.get<vector<JsonDeserializer>>(Player::BACKGROUND, "features"))
        backgroundFeatures.push_back(Feature(feature_jd));
    this->background = Background::Builder()
        .name(jd.get<string>(Player::BACKGROUND, "name"))
        .description(jd.get<string>(Player::BACKGROUND, "description"))
        .suggestedCharacteristics(jd.get<string>(Player::BACKGROUND, "suggested_characteristics"))
        .equipment(backgroundEquipment)
        .features(backgroundFeatures)
        .build();

    for(const JsonDeserializer& playerClass_jd : jd.get<vector<JsonDeserializer>>(Player::PLAYER_CLASSES))
        this->playerClasses.push_back(PlayerClass(playerClass_jd));

    this->inspiration = jd.get<int>(Player::INSPIRATION);
    this->armorClass = jd.get<int>(Player::ARMOR_CLASS);
    this->initiative = jd.get<int>(Player::INITIATIVE);
    this->speed = jd.get<int>(Player::SPEED);

    for(const JsonDeserializer& item_jd : jd.get<vector<JsonDeserializer>>(Player::ITEMS)){
        this->items.push_back(Item::Builder()
            .name(item_jd.get<string>("name"))
            .description(item_jd.get<string>("description"))
            .build()
        );
    }

    for(const JsonDeserializer& spellcasting_jd : jd.get<vector<JsonDeserializer>>(Player::SPELLCASTINGS))
        this->spellcastings.push_back(Spellcasting(spellcasting_jd));
}

string Player::serialize() const
{
    JsonSerializer js;

    JsonSerializer abilityScores_js;
    for(const pair<string, int>& pair : this->abilityScores) 
        abilityScores_js.put(pair.first, pair.second);
    js.put(Player::ABILITY_SCORES, abilityScores_js.str());

    JsonSerializer skill_js;
    for(const pair<string, string>& pair : this->skills)
        skill_js.put(pair.first, pair.second);
    js.put(Player::SKILLS, skill_js.str());

    JsonSerializer description_js;
    description_js.put(Player::Description::NAME, this->description.getName());
    description_js.put(Player::Description::AGE, this->description.getAge());
    description_js.put(Player::Description::HEIGHT, this->description.getHeight());
    description_js.put(Player::Description::WEIGHT, this->description.getWeight());
    description_js.put(Player::Description::EYES, this->description.getEyes());
    description_js.put(Player::Description::SKIN, this->description.getEyes());
    description_js.put(Player::Description::HAIR, this->description.getHair());
    js.put(Player::DESCRIPTION, description_js.str());

    JsonSerializer personality_js;
    personality_js.put(Player::Personality::ALIGNMENT, this->personality.getAlignment());
    personality_js.put(Player::Personality::TRAITS, this->personality.getTraits());
    personality_js.put(Player::Personality::IDEALS, this->personality.getIdeals());
    personality_js.put(Player::Personality::BONDS, this->personality.getBonds());
    personality_js.put(Player::Personality::FLAWS, this->personality.getFlaws());
    js.put(Player::PERSONALITY, personality_js.str());

    js.put(Player::AFFILIATIONS, this->affiliations);
    js.put(Player::BACKSTORY, this->backstory);

    js.put(Player::RACE, this->race.serialize());
    js.put(Player::BACKGROUND, this->background.serialize());

    js.createList(Player::PLAYER_CLASSES);
    for(const PlayerClass& playerClass : this->playerClasses)
        js.addToList(Player::PLAYER_CLASSES, playerClass.serialize());

    js.put(Player::INSPIRATION, this->inspiration);
    js.put(Player::ARMOR_CLASS, this->armorClass);
    js.put(Player::INITIATIVE, this->initiative);
    js.put(Player::SPEED, this->speed);

    JsonSerializer hp_js;
    hp_js.put(Player::HitPoints::MAX_HP, this->hp.getMaxHP());
    hp_js.put(Player::HitPoints::CURRENT_HP, this->hp.getCurrentHP());
    hp_js.put(Player::HitPoints::TEMP_HP, this->hp.getTempHP());
    js.put(Player::HP, hp_js.str());

    JsonSerializer deathSaves_js;
    deathSaves_js.put(Player::DeathSaves::SUCCESSES, this->deathSaves.getSuccesses());
    deathSaves_js.put(Player::DeathSaves::FAILURES, this->deathSaves.getFailures());
    js.put(Player::DEATH_SAVES, deathSaves_js.str());

    JsonSerializer proficiencies_js;
    proficiencies_js.put(Player::Proficiencies::PROFICIENCY_BONUS, this->proficiencies.getProficiencyBonus());

    proficiencies_js.createList(Player::Proficiencies::SAVING_THROWS);
    for(const string& prof : this->proficiencies.getSavingThrows())
        proficiencies_js.addToList(Player::Proficiencies::SAVING_THROWS, prof);
    
    proficiencies_js.createList(Player::Proficiencies::SKILLS);
    for(const string& prof : this->proficiencies.getSkills())
        proficiencies_js.addToList(Player::Proficiencies::SKILLS, prof);

    proficiencies_js.createList(Player::Proficiencies::MISC);
    for(const string& prof : this->proficiencies.getMiscProficiencies())
        proficiencies_js.addToList(Player::Proficiencies::MISC, prof);

    js.put(Player::PROFICIENCIES, proficiencies_js.str());
    
    JsonSerializer money_js;
    money_js.put(Player::Money::COPPER, this->money.getCopper());
    money_js.put(Player::Money::SILVER, this->money.getSilver());
    money_js.put(Player::Money::ELECTRUM, this->money.getElectrum());
    money_js.put(Player::Money::GOLD, this->money.getGold());
    money_js.put(Player::Money::PLATINUM, this->money.getPlatinum());
    js.put(Player::MONEY, money_js.str());

    js.createList(Player::ITEMS);
    for(const Item& item : this->items)
        js.addToList(Player::ITEMS, item.serialize());

    js.createList(Player::SPELLCASTINGS);
    for(const Spellcasting& spellcasting : this->spellcastings)
        js.addToList(Player::SPELLCASTINGS, spellcasting.serialize());

    return js.str();
}