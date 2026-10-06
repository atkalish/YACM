#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "playerclasses/PlayerClass.h"
#include "Race.h"
#include "Background.h"
#include "Item.h"
#include "abilities/Ability.h"
#include "abilities/Feature.h"
#include "spellcasting/Spellcasting.h"

using namespace std;

class Player{
public:

    // in constructor
    class Description{    // make builders for these
    private:
        string name;
        string age;
        string height;
        string weight;
        string eyes;
        string skin;
        string hair;
    
    public:
        class Builder{
        private:
            string _name;
            string _age;
            string _height;
            string _weight;
            string _eyes;
            string _skin;
            string _hair;
        
        public:
            Builder() = default;

            Builder& name(const string& name){this->_name = name; return *this;}
            Builder& age(const string& age){this->_age = age; return *this;}
            Builder& height(const string& height){this->_height = height; return *this;}
            Builder& weight(const string& weight){this->_weight = weight; return *this;}
            Builder& eyes(const string& eyes){this->_eyes = eyes; return *this;}
            Builder& skin(const string& skin){this->_skin = skin; return *this;}
            Builder& hair(const string& hair){this->_hair = hair; return *this;}
            Player::Description build(){return Player::Description(this);}

            friend class Player::Description;
        };

    private:
        Description(Player::Description::Builder* builder){
            this->name = builder->_name;
            this->age = builder->_age;
            this->height = builder->_height;
            this->weight = builder->_weight;
            this->eyes = builder->_eyes;
            this->skin = builder->_skin;
            this->hair = builder->_hair;
        }

    public:
        Description() = default;
        const string& getName(){return this->name;}
        const string& getAge(){return this->age;}
        const string& getHeight(){return this->height;}
        const string& getWeight(){return this->weight;}
        const string& getEyes(){return this->eyes;}
        const string& getSkin(){return this->skin;}
        const string& getHair(){return this->hair;}
    
    };

    class Personality{
    private:
        string alignment;
        string traits;
        string ideals;
        string bonds;
        string flaws;

    public:
        class Builder{
        private:
            string _alignment;
            string _traits;
            string _ideals;
            string _bonds;
            string _flaws;

        public:
            Builder() = default;

            Builder& alignment(const string& alignment){this->_alignment = alignment; return *this;}
            Builder& traits(const string& traits){this->_traits = traits; return *this;}
            Builder& ideals(const string& ideals){this->_ideals = ideals; return *this;}
            Builder& bonds(const string& bonds){this->_bonds = bonds; return *this;}
            Builder& flaws(const string& flaws){this->_flaws = flaws; return *this;}
            Player::Personality build(){return Player::Personality(this);}

            friend class Player::Personality;
        };
    private:
        Personality(Player::Personality::Builder* builder){
            this->alignment = builder->_alignment;
            this->traits = builder->_traits;
            this->ideals = builder->_ideals;
            this->bonds = builder->_bonds;
            this->flaws = builder->_flaws;
        }
        
    public:
        Personality() = default;
        const string& getAlignment(){return this->alignment;}
        const string& getTraits(){return this->traits;}
        const string& getIdeals(){return this->ideals;}
        const string& getBonds(){return this->bonds;}
        const string& getFlaws(){return this->flaws;}
    };

    class HitPoints{
    private:
        int maxHP;
        int currentHP;
        int tempHP;
        HitPoints() = default;
        HitPoints(int maxHP, int currentHP, int tempHP){
            this->maxHP = maxHP;
            this->currentHP = currentHP;
            this->tempHP = tempHP;
        }

    public:
        int getMaxHP(){return this->maxHP;}
        int getCurrentHP(){return this->currentHP;}
        int getTempHP(){return this->tempHP;}

        void setMaxHP(int maxHP){this->maxHP = maxHP;}
        void setcurrentHP(int currentHP){this->currentHP = currentHP;}
        void setTempHP(int tempHP){this->tempHP = tempHP;}

        friend class Player;
    };

    class DeathSaves{
    private:
        int successes = 0;
        int failures = 0;
        DeathSaves() = default;
    public:
        int getSuccesses() const {return this->successes;}
        int getFailures() const {return this->failures;}
        
        void setSuccesses(int successes){this->successes = successes;}
        void setFailures(int failures){this->failures = failures;}

        friend class Player;
    };

    class Proficiencies{
    private:
        int proficiencyBonus;
        unordered_set<string> savingThrows;
        unordered_set<string> skills; // passive perception goes in here
        Proficiencies() = default;
    public:
        int getProficiencyBonus() const {return this->proficiencyBonus;}    
        const unordered_set<string>& getSavingThrows() const {return this->savingThrows;}
        const unordered_set<string>& getSkills() const {return this->skills;}

        void addSavingThrowProficiency(string proficiency){this->savingThrows.insert(proficiency);}
        void addSkillProficiency(string proficiency){this->skills.insert(proficiency);}
        
        friend class Player;
    };

    class Money{
    private:
        int copper = 0;
        int silver = 0;
        int electrum = 0;
        int gold = 0;
        int platinum = 0;
    public:
        Money() = default;
        Money(int copper, int silver, int electrum, int gold, int platinum){
            this->copper = copper;
            this->silver = silver;
            this->electrum = electrum;
            this->gold = gold;
            this->platinum = platinum;
        }
        int getCopper() const {return this->copper;}
        int getSilver()const {return this->silver;}
        int getElectrum() const {return this->electrum;}
        int getGold() const {return this->gold;}
        int getPlatinum() const {return this->platinum;}

        void setCopper(int copper){this->copper = copper;}
        void setSilver(int silver){this->silver = silver;}
        void setElectrum(int electrum){this->electrum = electrum;}
        void setGold(int gold){this->gold = gold;}
        void setPlatinum(int platinum){this->platinum = platinum;}

        Money operator+(const Money& other);
        Money operator-(const Money& other);
        Money operator+=(const Money& other);
        Money operator-=(const Money& other);

        friend class Player;
    };

private:
    unordered_map<string, int> abilityScores;

    Description description;
    Personality personality;

    string affiliations;
    string backstory;
    Race race;
    Background background;
    vector<PlayerClass> playerClasses;
    int inspiration = 0;
    int armorClass;
    int initiative;
    int speed;

    HitPoints hp;
    DeathSaves deathsaves;
    Proficiencies proficiencies;
    Money money;

    vector<Item> items;
    vector<Feature> features;
    vector<Spellcasting> spellcasting;

public:
    class Builder{
    private:
        unordered_map<string, int> _abilityScores;

        Description _description;
        Personality _personality;

        string _affiliations;
        string _backstory;
        
        Race _race;
        Background _background;
        vector<PlayerClassBlueprint> _playerClasseBlueprints;

    public:
        Builder() = default;
        Builder& abilityScores(const unordered_map<string, int>& abilityScores){this->_abilityScores = abilityScores; return *this;}
        Builder& description(const Description& description){this->_description = description; return *this;}
        Builder& personality(const Personality& personality){this->_personality = personality; return *this;}
        Builder& affiliations(const string& affiliations){this->_affiliations = affiliations; return *this;}
        Builder& backstory(const string& backstory){this->_backstory = backstory; return *this;}
        Builder& race(const Race& race){this->_race = race; return *this;}
        Builder& background(const Background& background){this->_background = background; return *this;}
        Builder& playerClasses(const vector<PlayerClassBlueprint> playerClassBlueprints){this->_playerClasseBlueprints = playerClassBlueprints; return *this;}
        Player build(){return Player(this);}

        friend class Player;
    };

private:
    Player(Player::Builder* builder){
        this->abilityScores = builder->_abilityScores;
        this->description = builder->_description;
        this->personality = builder->_personality;
        this->affiliations = builder->_affiliations;
        this->backstory = builder->_backstory;
        this->race = builder->_race;
        this->background = builder->_background;
        
        // need to extend to modify values in Player based off of these blueprints
        for(PlayerClassBlueprint blueprint : builder->_playerClasseBlueprints) this->playerClasses.push_back(PlayerClass(blueprint));

    }
    
public:
    Player() = default;
    ~Player();

    const unordered_map<string, int>& getAbilityScores() const {return this->abilityScores;}
    const Description& getDescription() const {return this->description;}
    const Personality& getPersonality() const {return this->personality;}
    const string& getAffiliation() const {return this->affiliations;}
    const string& getBackstory() const {return this->backstory;}
    const Race& getRace() const {return this->race;}
    const Background& getBackground() const {return this->background;}

    const vector<PlayerClass>& getPlayerClasses() const {return this->playerClasses;}
    int getInspiration() const {return this->inspiration;}
    int getArmorClass() const {return this->armorClass;}
    int getInitiative() const {return this->initiative;}
    int getSpeed() const {return this->speed;}
    const HitPoints& getHP() const {return this->hp;}
    const DeathSaves& getDeathSaves() const {return this->deathsaves;}
    const Proficiencies& getProficiencies() const {return this->proficiencies;}
    const Money& getMoney() const {return this->money;}
    const vector<Item>& getItem() const {return this->items;}
    //const vector<Feature> getFeatures(){return this->features;}
    const vector<Spellcasting>& getSpellcasting() const {return this->spellcasting;}
    
    void addMoney(const Money& money){this->money += money;}
    void removeMoney(const Money& money){this->money -= money;}
    void setInspiration(int inspiration){this->inspiration = inspiration;}
    void setArmorClass(int armorClass){this->armorClass = armorClass;}
    void setInitiative(int initiative){this->initiative = initiative;}
    void setSpeed(int speed){this->speed = speed;}
    void setHp(const HitPoints& hp){this->hp = hp;}
    void succeedDeathSave(){this->deathsaves.setSuccesses(this->getDeathSaves().getSuccesses()+1);}
    void failDeathDave(){this->deathsaves.setFailures(this->getDeathSaves().getFailures()+1);}
    void incrementProficiencyBonus(){++this->proficiencies.proficiencyBonus;}
    void addItem(const Item& item){this->items.push_back(item);}
    //void addFeature(const Feature& feature){this->features.push_back(feature);}

    // add a lot of function declarations
    void addPlayerClass(const PlayerClassBlueprint& blueprint);
    void addproficiency(const string& key, const string& proficiency);
    void addSpellcasting(const SpellcastingBlueprint& blueprint);

private:
    // this will set the speed, based on race, money/items based on background, etc
    void initializeValues();
};