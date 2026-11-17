#include "../../../include/player/features/Ability.h"

Ability::Ability(const string& jsonPath) {
	JsonDeserializer jd(Ability::SRC_DIR + jsonPath);
	*this = Ability(jd);
}

Ability::Ability(const JsonDeserializer& jd){
	this->text = jd.get<string>("description");
	this->hidden = jd.get<bool>("hidden");

	try {
		this->scaler = Scaler();
		this->scaler.name = jd.get<string>("scaler", "name");
		for(string scaling : jd.get<vector<string>>("scaler", "scaling")) this->scaler.scaling.push_back(scaling);
		this->hasScaler = true;
	} catch (...) {
		this->hasScaler = false;
	}

	try {
		this->chargeType = ChargeType();
		this->chargeType.name = jd.get<string>("charge_type", "name");
		this->chargeType.count = jd.get<string>("charge_type", "count");
		for(string rechargeHook : jd.get<vector<string>>("charge_type", "recharge_hooks")) this->chargeType.rechargeHooks.push_back(rechargeHook);
		this->chargeType.rechargeVal = jd.get<string>("charge_type", "recharge_val");

		this->hasCharge = true;
	} catch(...) {
		this->hasCharge = false;
	}
}

string Ability::serialize() const {
	JsonSerializer js;
	js.put("description", this->text);
	js.put("hidden", this->hidden);

	if(this->hasScaler){
		JsonSerializer scaler_js;
		scaler_js.put("name", this->scaler.name);
		scaler_js.put("count", this->scaler.scaling);
		js.put("scaler", scaler_js.str());
	}else{
		js.put("scaler", "{}");
	}

	if(this->hasCharge){
		JsonSerializer charge_js;
		charge_js.put("name", this->chargeType.name);
		charge_js.put("count", this->chargeType.count);
		for(const string& hook : this->chargeType.rechargeHooks) charge_js.addToList("charge_type", hook);
		charge_js.put("recharge_val", this->chargeType.rechargeVal);
		js.put("charge_type", charge_js.str());
	}else{
		js.put("charge_type", "{}");
	}
    return js.str();
}
