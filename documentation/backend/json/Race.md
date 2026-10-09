# Race
the race of the player character

## Race JSON Structure
```json
{
    "json_type": "RACE",
    "name": "race_name",
    "description": "race_description",
    "speed": "race_speed",
    "features": [
        "*/features/*/feature.json"
    ]

}
```

## Race Fields
- `json_type` this field must be "RACE"
- `name` the name of the race
- `description` a description of the race
- `speed` the movement speed of the race as an integer
- `features` this is a list of relative paths to all features associated with this item. This includes anything that modifies the players in anyway, such as languages, ability score improvements, or darkvision.

## Related Links
- [Feature](features/Feature.md)