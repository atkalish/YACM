#pragma once

#include <string>
#include <vector>
#include "features/TraitModification.h"
#include "features/Selector.h"
#include "features/Feature.h"
#include "Item.h"

using namespace std;

class Background{
private:
    string name;
    string description;
    vector<Item> equipment;
    vector<Feature> features;
    string suggestedCharacteristics;

public:
    class Builder{
    private:
        string _name;
        string _description;
        vector<Item> _equipment;
        vector<Feature> _features;
        string _suggestedCharacteristics;

    public:
        Builder() = default;

        Builder& name(const string& name){this->_name = name; return *this;}
        Builder& description(const string& description){this->_description = description; return *this;}
        Builder& equipment(const vector<Item> equipment){this->_equipment = equipment; return *this;}
        Builder& features(const vector<Feature> features){this->_features = features; return *this;}
        Builder& suggestedCharacteristics(const string& suggestedCharacteristics){this->_suggestedCharacteristics = suggestedCharacteristics; return *this;}
        Background build(){return Background(this);}
        friend class Background;
    };

private:
    Background(Background::Builder* builder){
        this->name = builder->_name;
        this->description = builder->_description;

        this->equipment = builder->_equipment;
        this->features = builder->_features;
        this->suggestedCharacteristics = builder->_suggestedCharacteristics;
    }

public:
    Background() = default;
    ~Background();

    const string& getname(){return this->name;}
    const string& getDescription(){return this->description;}
    const vector<Item>& getEquipment(){return this->equipment;}
    const string getSuggestedCharacteristics(){return this->suggestedCharacteristics;}
};
