# Spell Selector
Fundamentally the spell selector is the same concept as a Selector.
The only difference is that it sometimes does replacement and modifies
a list outside of itself-- internally, a selector handles its list inside
itself where a spell selector modifies a list inside of a Spellcasting instance.

## Spell Selector JSON Structure
```json
{
    "description": "text text text text text",
    "replaces_spells": false,
    "hooks": [ "long rest", "short rest", "dawn" ],
    "min_selection": "formula",
    "max_selection": "formula",
    "level": 0,
}
```

## Ability Fields
- `description`: the description/flavor text of this replacement. For example, Cantrip versatility
- `replaces_spells`: whether or not you're replacing spells when doing the selection
- `hooks`: assorted hooks when the selection should trigger
- `min_selection`: a mathematical formula for how many spells you may select on a hook trigger
- `max_selection`: minimum selection but actually maximum
- `level`: what level of spell it should effect. Leave blank for any level, 0 for cantrips

## Related Links
- [Spellcasting](Spellcasting.md)
