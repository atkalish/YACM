#pragma once
#include <string>
#include <vector>
#include "../../serdes/JsonDeserializer.h"

using namespace std;
typedef string Formula;

class Ability{
public:
    class Scaler{
    private:
        string name;
        vector<Formula> scaling;
    public:
        Scaler() = default;
        Scaler(const string& name, const vector<Formula>& scaling){
            this->name = name;
            this->scaling = scaling;
        }
			friend class Ability;
    };
    class ChargeType{
    private:
				string name;
        Formula count;
        vector<string> rechargeHooks;
        Formula rechargeVal;
    public:
        ChargeType() = default;
        ChargeType(const string& name, int count, const vector<string>& rechargeHooks, const string& rechargeVal){
						this->name = name;
            this->count = count;
            this->rechargeHooks = rechargeHooks;
            this->rechargeVal = rechargeVal;
        }
				friend class Ability;
    };
private:
		inline static const string SRC_DIR = "data/resources/features/abilities/";
    string text;
    bool hidden;
		bool hasScaler;
		bool hasCharge;
    Scaler scaler;
    ChargeType chargeType;

public:
    class Builder {
		private:
        string _text;
        bool _hidden;
				bool _hasScaler;
				bool _hasCharge;
        Scaler _scaler;
        ChargeType _chargeType;

	public:
			Builder() {this->_hasCharge = false; this->_hasScaler = false;};
			Builder& text(const string& text){this->_text = text; return *this;}
			Builder& hidden(bool hidden){this->_hidden = hidden; return *this;}
			Builder& scaler(const Scaler& scaler){this->_scaler = scaler; this->_hasScaler = true; return *this;}
			Builder& charges(const ChargeType& chargeType){this->_chargeType = chargeType; this->_hasCharge = true; return *this;}
			Ability build(){return Ability(this);}
			friend class Ability;
    };

protected:
	Ability(Builder* builder){
		this->text = builder->_text;
		this->hidden = builder->_hidden;
		this->hasCharge = builder->_hasCharge;
		this->hasScaler = builder->_hasScaler;
		if(builder->_hasScaler) this->scaler = builder->_scaler;
		if(builder->_hasCharge) this->chargeType = builder->_chargeType;
	}

public:
	Ability(const string& jsonPath);
	const string& getText() const {return this->text;}
	bool isHidden() const {return this->hidden;}
	const Scaler* getScaler() const {
		if(hasScaler) return &this->scaler;
		else return nullptr;
	}
	const ChargeType* getChargeType() const {
		if(hasCharge) return &this->chargeType;
		else return nullptr;
	}
	Ability() = default;
};
