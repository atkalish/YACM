# Selector
A Selector is a generic wrapper. It allows for repeated selection
from a super list to modify a main list. For example, githyanki's
Astral knowledge lets the player select a skill proficiency to know
every long rest. So the super list is all skill proficiencies, and the
main list is a list of length 1 that is the used skill. As stated, it
is very generic, and can be used on abilities and trait modifications;
however due to certain technical necessities please use spellselectors
instead of selector for spells and spell list modifications.

## Selector JSON Structure
```json
{
    "type": "ability",
    "super_list": ["directory/", "file.json", "file2.json"],
    "hooks": [ "long rest", "level up", "custom hook1" ],
    "minimum_count": "formula",
    "maximum_count": "formula"
}
```
## Selector Fields
- `type`: this fild may be "ability" or "trait modification"
- `super_list`: this is a list of places to look from that are unioned to create the list to select from. You may include directories and files, which will be parsed as the type provided
- `hooks`: a list of hooks that the selector will trigger on, e.g. "level up" or "dawn"
- `minimum_count`: a mathematical formula indicating the minimum amount that may be selected on a hook
- `maximum_count`: same as `minimum_count`, but the maximum amount.

## Related Links
- [Spell Selector](../spellcasting/SpellSelector.md)
- [Ability](Ability.md)
- [Trait Modification](TraitModification.md)
