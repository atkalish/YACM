#include "../../../include/player/features/Ability.h"

Ability::Ability(const string& jsonPath) {
	JsonDeserializer jd(Ability::SRC_DIR + jsonPath);
	this->text = jd.get<string>("description");
	this->hidden = jd.get<bool>("hidden");

	try {
		this->scaler = Scaler();
		this->scaler.name = jd.get<string>("scaler", "scaler_name");
		for(string scaling : jd.get<vector<string>>("scaler", "formula")) this->scaler.scaling.push_back(scaling);
		this->hasScaler = true;
	} catch (...) {
		this->hasScaler = false;
	}

	try {
		this->chargeType = ChargeType();
		this->chargeType.name = jd.get<string>("charge_type", "name");
		this->chargeType.count = jd.get<string>("charge_type", "formula");
		for(string rechargeHook : jd.get<vector<string>>("charge_type", "recharge_hooks")) this->chargeType.rechargeHooks.push_back(rechargeHook);
		this->chargeType.rechargeVal = jd.get<string>("charge_type", "recharge_val");

		this->hasCharge = true;
	} catch(...) {
		this->hasCharge = false;
	}
}
