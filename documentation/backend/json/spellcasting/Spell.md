# Spell
A spell is a spell.... what more do you want?
## Spell JSON Structure
```json
{
    "name": "spell name",
    "description": "spell description",
    "level": 1,
    "source": "spell source",
    "school": "spell school",
    "ritual": false,
    "casting_time": "spell casting time",
    "range": "spell range",
    "componenents": "spell components",
    "duration": "spell duration",
    "higher_levels": "spell at higher level",
    "tags": [
        
    ]
}
```



## Spell Fields
`name` the name of the spell.
`description` the description of the spell.
`source` the source book or other place of origin of this spell.
`level` the level of this spell. Specify 0 for a cantrip.
`school` the school of magic that this spell belongs to.
`ritual` whether or not this spell can be cast ritually.
`casting_time` the time it takes to cast this spell.
`range` the range of this spell.
`components` the material components required for this spell.
`duration` the length of this spell. Also where specifies if concentration is required.
`higher_level` the effects of casting this spell at a higher level.
`tags` any additional information associated with this spell for the purpose of searching.
