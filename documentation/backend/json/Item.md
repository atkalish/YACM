# Item
Any dnd item ranging from magical items and weapons to a surprisingly long amount of rope.

## Item JSON Structure
```json
{
    "name": "item_name",
    "description": "item_description",
    "features": [
        "*/feature.json"
    ]
}
```
## Item Fields
- `name` the name of the item.
- `description` the description of the item includes any non functional information about the item.
- `features` this is a list of relative paths to all features associated with this item. 

## Related Links
- [Feature](features/Feature.md)