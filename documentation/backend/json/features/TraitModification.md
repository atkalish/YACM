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
- `target_id`: target id is the name of the trait that you are trying to modify
- `formula`: a mathematical formula for what you're modifying by

## Related Links
- [Feature](Feature.md)
- [Ability](Ability.md)

## Proficiencies
if aidan hasn't filled this out by the time that you
read this, find aidan and make aidan do that
