#pragma once
#include <string>
#include <vector>

using namespace std;

class Spell{
private:
    string name;
    int level;
    string source;
    string school;
    bool ritual;
    string castingTime;
    string range;
    string components;
    string duration;
    string description;
    string higherLevel;
    vector<string> tags;

public:
    class Builder{
    private:
        string _name;
        int _level;
        string _source;
        string _school;
        bool _ritual;
        string _castingTime;
        string _range;
        string _components;
        string _duration;
        string _description;
        string _higherLevel;
        vector<string> _tags;

	public:
		Builder() = default;

		Builder& name(const string& name){this->_name = name; return *this;}
        Builder& level(int level){this->_level = level; return *this;}
		Builder& source(const string& source){this->_source = source; return *this;}
		Builder& school(const string& school){this->_school = school; return *this;}
		Builder& ritual(bool ritual){this->_ritual = ritual; return *this;}
		Builder& castingTime(const string& castingTime){this->_castingTime = castingTime; return *this;}
		Builder& range(const string& range){this->_range = range; return *this;}
		Builder& components(const string& components){this->_components = components; return *this;}
		Builder& duration(const string& duration){this->_duration = duration; return *this;}
		Builder& description(const string& description){this->_description = description; return *this;}
		Builder& higherLevel(const string& higherLevel){this->_higherLevel = higherLevel; return *this;}
		Builder& tags(const vector<string>& tags){this->_tags = tags; return *this;}
        Spell build(){return Spell(this);}

		friend class Spell;
    };

private:
    Spell(Spell::Builder* builder){
        this->name = builder->_name;
        this->level = level;
        this->source = builder->_source;
        this->school = builder->_school;
        this->ritual = builder->_ritual;
        this->castingTime = builder->_castingTime;
        this->range = builder->_range;
        this->components = builder->_components;
        this->duration = builder->_duration;
        this->description = builder->_description;
        this->higherLevel = builder->_description;
        this->tags = builder->_tags;
    }

public:
    Spell() = default;

	const string& getName(){return this->name;}
    int getLevel(){return this->level;}
	const string& getSource(){return this->source;}
	const string& getSchool(){return this->school;}
	bool isRitual(){return this->ritual;}
	const string& getCastingTime(){return this->castingTime;}
	const string& getRange(){return this->range;}
	const string& getComponents(){return this->components;}
	const string& getDuration(){return this->duration;}
	const string& getDescription(){return this->description;}
	const string& getHigherLevel(){return this->higherLevel;}
	const vector<string>& getTags(){return this->tags;}
};
