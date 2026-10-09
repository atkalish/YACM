# Background
description

## Background JSON Structure
```json
{
    "json_type": "BACKGROUND",
    "name": "description",
    "equipment": [
        "*/items/*/item.json"
    ],
    "features": [
        "*/features/*/feature.json"
    ],
    "suggested_characteristics": "suggested_characteristics"
}
```

## Background Fields
- `json_type` this field must be "BACKGROUND".
- `name` the name of the background.
- `equipment` this is a list of all relative paths to equipment the player character receives for choosing this background.
- `features` this is a list of relative paths to all features associated with this background.
- `suggested_characteristics` this is text describing suggested characteristics that someone with this background might have.

## Related Links
- [Item](Item.md)
- [Feature](features/Feature.md)