#pragma once

#include <vector>
#include <string>
#include "../features/Feature.h"
#include "../../serdes/JsonDeserializer.h"
#include "../../serdes/JsonSerializer.h"

using namespace std;

class PlayerSubclass{
private:
    string name;
    string description;
    vector<vector<Feature>> featureTable;

public:
    inline static const string SRC_DIR = "data/resources/playerclasses/playersubclasses/";
    class Builder{
    private:
        string _name;
        string _description;
        vector<vector<Feature>> _featureTable;

    public:
        Builder() = default;

        Builder& name(const string& name){this->_name = name; return *this;}
        Builder& description(const string& description){this->_description = description; return *this;}
        Builder& featureTable(const vector<vector<Feature>> featureTable){this->_featureTable = featureTable; return *this;}
        PlayerSubclass build(){return PlayerSubclass(this);}
        friend class PlayerSubclass;
    };

private:
    PlayerSubclass(PlayerSubclass::Builder* builder){
        this->name = builder->_name;
        this->description = builder->_description;
        this->featureTable = builder->_featureTable;
    }

public:
    PlayerSubclass(const string& jsonPath);
    PlayerSubclass() = default;
    ~PlayerSubclass() = default;

    string serialize() const;

    const string& getName() const {return this->name;}
    const string& getDscription() const {return this->description;}
    const vector<vector<Feature>>& getFeatureTable() const {return this->featureTable;}
};