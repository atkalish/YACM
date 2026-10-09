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
    "armor_proficiency_count": 1,
    "armor_proficiencies": [
        "armor"
    ],
    "weapon_proficiency_count": 1,
    "weapon_proficiencies": [
        "weapon"
    ],
    "tool_proficiency_count": 1,
    "tool_proficiencies": [
        "tool"
    ],
    "saving_throw_proficiencies": 1,
    "saving_throw_proficiencies": [
        "saving_throw"
    ],
    "skill_proficiencies": 1,
    "skill_proficiencies": [
        "skill"
    ],
    "equipment_proficiencies": 1,
    "equipment_proficiencies": [
        "equipment"
    ],
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
- `armor_proficiency_count` how many of the listed armor proficiencies the player can choose
- `armor_proficiencies` a list of strings representing armor
- `weapon_proficiency_count` how many of the listed weapon proficiencies the player can choose
- `weapon_proficiencies` a list of strings representing weapons
- `tool_proficiency_count` how many of the listed tool proficiencies the player can choose
- `tool_proficiencies` a list of strings representing tools
- `saving_throw_proficiency_count` how many of the listed saving throw proficiencies the player can choose
- `saving_throw_proficiencies` a list of strings representing saving throws
- `skill_proficiency_count` how many of the listed skill proficiencies the player can choose
- `skill_proficiencies` a list of strings representing skills
- `equipment_proficiency_count` how many of the listed equipment proficiencies the player can choose
- `equipment_proficiencies` a list of strings representing equipment
- `spell_list` path to the list of spells for this spellcasting. Empty string if not applicable
- `spellcasting` path to spellcasting json. Empty string if not applicable.

## Related Links
- [Feature](../features/Feature.md)
- [Spellcasting](../spellcasting/Spellcasting.md)
- [SpellList](../spellcasting/Spellcasting.md)
- [PlayerSubclass](PlayerSubclass.md)