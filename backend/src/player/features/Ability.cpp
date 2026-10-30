#include "../../../include/player/features/Ability.h"

Ability::Ability(const string& jsonPath) {
	JsonDeserializer jd(Ability::SRC_DIR + jsonPath);
	this->text = jd.get<string>("description");
	this->hidden = jd.get<bool>("hidden");

	try {
		this->scaler = scaler();
		this->scaler.name = jd.get<string>("scaler", "scaler_name");
		this->scaler.scaling = jd.get<string>("scaler", "formula");
		this->hasScaler = true;
	} catch (...) {
		this->hasScaler = false;
	}

	try {
		this->chargeType = chargeType();
		this->chargeType.name = jd.get<string>("charge_type", "name");
		this->chargeType.count = jd.get<string>("charge_type", "formula");
		this->chargeType.rechargeHooks = jd.get<string>("charge_type", "recharge_hooks");
		this->chargeType.recharge_val = jd.get<string>("charge_type", "recharge_val");

		this->hasCharge = true;
	} catch(...) {
		this->hasCharge = false;
	}
}
