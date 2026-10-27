# Trait Modification
A trait modification is like an ability, however it modifies a 
value within the player. For example, a monk gains faster movement
speed on level ups, so that is a trait modification on the player's
movement speed. If a trait does not exist, it will be initialized to
zero before being acted upon. Please see below for proficiencies.

## Trait Modification JSON Structure
```json
{
    "target_id": "initiative",
    "formula": "formula"
}
```

## Trait Modification Fields
- `target_id`: target id is the name of the trait that you are trying to modify. See ReservedKeywords.
- `formula`: a mathematical formula for what you're modifying by. Leave as an empty string if not applicable.

## Related Links
- [Feature](Feature.md)
- [Ability](Ability.md)
- [Formula](../../Formula.md)
- [Reserved Keywords](../../ReservedKeywords.md)
