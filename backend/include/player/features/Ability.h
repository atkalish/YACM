#pragma once
#include <string>
#include <vector>

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
    };
private:
    string text;
    bool hidden;
    Scaler scaler;
 
    ChargeType chargeType;

public:
    class Builder {
		private:
        string _text;
        bool _hidden;
        Scaler _scaler;
        ChargeType _chargeType;

	public:
        Builder() = default;
        Builder& text(const string& text){this->_text = text; return *this;}
        Builder& hidden(bool hidden){this->_hidden = hidden; return *this;}
        Builder& scaler(const Scaler& scaler){this->_scaler = scaler; return *this;}
        Builder& charges(const ChargeType& chargeType){this->_chargeType = chargeType; return *this;}
        Ability build(){return Ability(this);}
			friend class Ability;
    };

protected:
    Ability(Builder* builder){
        this->text = builder->_text;
        this->hidden = builder->_hidden;
        this->scaler = builder->_scaler;
        this->chargeType = builder->_chargeType;
    }

public:
    const string& getText() const {return this->text;}
    bool isHidden() const {return this->hidden;}
    const Scaler& getScaler() const {return this->scaler;}
    const ChargeType& getChargeType() const {return this->chargeType;}
		Ability() = default;
};
