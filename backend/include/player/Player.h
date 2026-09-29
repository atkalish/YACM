#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "playerclasses/PlayerClass.h"
#include "Race.h"
#include "Background.h"
#include "Item.h"
#include "Ability.h"
#include "spellcasting/Spellcasting.h"

using namespace std;

class Player{
private:

    // in constructor
     struct Description{    // make builders for these
        string characterName;
        string age;
        string height;
        string weight;
        string eyes;
        string skin;
        string hair;
    } description;

     struct Personality{    // make builders for these
        string alignment;
        string traits;
        string ideals;
        string bonds;
        string flaws;
    } personality;

    unordered_map<string, int> abilityScores;

    string affiliations;
    string backstory;

    // pass in the blue print
    Race race;
    Background background;
    vector<PlayerClass> playerClasses;





    // 
    int inspiration;
    
    // determined by other information
    int armorClass;
    int initiative;
    int speed;

    struct HP{
        int maxHP;
        int currentHP;
        int tempHP;
    } hp;
    
    struct HitDice{
        int maxHitdice;
        int currentHitDice;
    } hitDie;

    struct DeathSaves{
        int successes;
        int failures;
    } deathSaves;

    struct Proficiencies{
        int proficiencyBonus;
        unordered_set<string> savingThrows;
        unordered_set<string> skills; // passive perception goes in here
    } proficiencies;
    
    struct Money{
        int copper;
        int silver;
        int electrum;
        int gold;
        int platinum;
    } money;

    vector<Item> equipment;

    vector<Ability*> features;

    vector<Spellcasting> spellcasting;


};