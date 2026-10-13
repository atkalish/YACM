# Spellcasting
Spellcasting is the ability to cast spells and provides spell save, spell attack, spell saves, and etc.
## Spellcasting JSON Structure
```json
{
    "focus": "spellcasting focus",
    "spell_list": [
        "*/spell_list.json"
    ],
    "spell_selectors": [
        "*/spell_selector.json"
    ],
    "ritual": false,
    "spell_ability_info": "spellcasting info",
    "spell_save_formula": "spell save formula",
    "spell_attack_formula": "spell attack formula",
    "spell_preparation": "spell preparation info",
    "spells_known": "spells known",
    "spell_slots": [
        [2,2,0,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
        [2,3,2,0,0,0,0,0,0,0],
    ]
}
```
## Spell castingFields
- `focus` spellcasting focus you can use for this spellcasting.
- `spell_list` a list of paths to spell lists that this spellcasting has access to.
- `spell_selectors` a selector for spells within the spellcasting.
- `ritual` whether or not this spellcasting can cast spells ritually.
- `spell_ability_info` any information about using a spell ability to cast a spell.
- `spell_save_formula` the formula for a spell save with this spellcasting.
- `spell_attack_formula` the formula for a spell attack with this spellcasting.
- `spell_preparation` any information about preparing spells for this spellcasting.
- `spells_known` any information about the spells that are known.
- `spell_slots` a table that specifies the number of each leveled spell slots that are available at each level. The first slot represents a cantrip, the second a 1st level spell, and so on. This table may be completely zeroed out if the instance of spellcasting provides no spell slots.

## Related Links
- [Formula](../../Formula.md)
- [Spell List](SpellList.md)