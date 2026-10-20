# Player Class
A class for the player character

## Player Class JSON Structure
```json
{
    "name": "player_class_name",
    "description": "player_class_description",
    "multi_class_prereqs": "multi_class_prereqs",
    "feature_table": [
        ["*/feature.json"],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        []
    ],
    "hit_die": 8,
    "first_level_hit_points": "first_level_hit_points",
    "higher_level_hit_points": "higher_level_hit_points",
    "subclasses": [
        "*/subclass.json"
    ],
    "subclass_level": 3,
    "class_proficiencies": [
        "*/feature.json"
    ],
    "starting_equipment": [
        ["*/item_option1.json", "*/item_option2.json"],
        ["*/itemoptions"]
    ]
    "spell_list": "*/spell_list",
    "spellcasting": "*/spellcasting.json"
}
```

## Player Class Fields
- `name` the name of the player class.
- `description` the description of the player class.
- `multi_class_prereqs` requirements for multi classing into this class such as a minimum dexterity requirement.
- `feature_table` a table representing the different features that a player will have at different levels of this class.
- `hit_die` an integer representing the hit die for this class. (e.g., 8 for a d8)
- `first_level_hit_points` a string formula to calculate first level hit points.
- `higher_level_hit_points` a string formula to calculate higher level hit points.
- `subclasses` a list of relative paths to subclasses of this player class.
- `subclass_level` the level subclasses are unlocked for this player class.
- `class_proficiencies` a list of features that are intended to modify the proficiencies that the player has
- `starting_equipment` a list of a list of equipment options for this class. Each sublist is intended as a choice.
- `spell_list` path to the list of spells for this spellcasting. Empty string if not applicable
- `spellcasting` path to spellcasting json. Empty string if not applicable.

## Related Links
- [Feature](../features/Feature.md)
- [Spellcasting](../spellcasting/Spellcasting.md)
- [SpellList](../spellcasting/Spellcasting.md)
- [PlayerSubclass](PlayerSubclass.md)
