# Feature
A feature is a collection of abilities and trait modifications. In essence,
it is the top-level of *things* that a class, race, ability, etc provide. A
dragonborn's breath weapon, a rogue's sneak attack, a druid's wild shape,
a monk's unarmored movement, etc etc.

## Feature JSON Structure
```json
{
    "name": "feature name",
    "description": "text text text text",
    "prereq": "you need to kill god to get this ability",
    "tags": [ "tag1", "tag2", "tag3" ],
    "optional": false,

    "spellcasting": "file.json";
    "exclusive_selection": false,
    "base_abilities": ["directory1/", "directory2/", "file1.json", "file2.json"],
    "base_trait_modifications": ["directory1/", "directory2/", "file1.json", "file2.json"],
    "ability_selectors": ["directory1/", "directory2/", "file1.json", "file2.json"],
    "trait_modification_selectors": ["directory1/", "directory2/", "file1.json", "file2.json"],
}
```

## Ability Fields
- `name`: the name of the feature
- `description`: the description for the feature, just cosmetic
- `prereq`: the prerequisites for the feature, just cosmetic
- `tags`: a list of tags for searching. Do not include hooks here.
- `optional`: whether or not a player can elect to pass up this feature
- `spellcasting`: the path to the spellcasting a feature provides, simply leave blank if it is not provided
- `exclusive_selection`: true when you may choose exclusively ability selectors OR (xor) trait modification selectors on a hook. For things such as ability score increase xor a feat
- `base_abilities`: paths to the abilities and directories holding abilities that will be unioned to create the base abilities, what is always provided by the feature
- `ability_selectors`: paths to the ability selectors and directories holding ability selectors. These are for features that change and the player may modify, for example a warlock keeps getting more invocations each level. Consider it to be the 'mutable' portion to the base's immutability
- `base_trait_modifications`: like base abilities, but for trait modifications
- `trait_modification_selectors`: like ability selectors, but for trait modifications

## Related Links
- [Feature](Feature.md)
- [Trait](TraitModification.md)
- [Spellcasting](../spellcasting/Spellcasting.md)
