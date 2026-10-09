# Player Class
description

## Player Class JSON Structure
```json
{
    "json_type": "PLAYER_CLASS",
    "name": "player_class_name",
    "description": "player_class_description",
    "multi_class_prereqs": "multi_class_prereqs",
    "feature_table": [
        ["*/features/*/feature.json"],
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
        "*/subclasses/*/subclass.json"
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
    "spellcasting": "*/spellcasting/*/spellcasting.json"
}
```

## Player Class Fields
`json_type` this field must be "PLAYER_CLASS"
`name`
`description`

## Related Links
- [Feature](../features/Feature.md)
- [Spellcasting](../spellcasting/Spellcasting.md)