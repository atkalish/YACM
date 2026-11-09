#include "../../../include/player/spellcasting/Spellcasting.h"

string Spellcasting::serialize() const {
    JsonSerializer js;
    js.put("blueprint", this->blueprint.serialize());

    for(const Spellcasting::SpellWrapper& spellWrapper : this->spellList){
        JsonSerializer spellWarpper_js;
        spellWarpper_js.put("spell", spellWrapper.spell.serialize());
        spellWarpper_js.put("repared", spellWrapper.prepared);
    }

    js.createList("spell_slots");
    for(int i = 0; i < 9; ++i) js.addToList("spell_slots", this->spellSlots[i]);

    return js.str();
}