# Ability
An ability that *things* may provide.
This includes anything from a dragonborn's breath weapon to a monk's martial
arts dice. An ability is atomic, meaning that anything that is compound may need
to be divided into multiple abilities. For example, Monk's martial arts do not need
to be divided; you will find that it is possible to model it inside a single ability.
On the other hand, a magic item might provide the ability to have a bonus to attack rolls,
and provide proficiency in some skill. You will find it is instead best to model this as a feature
with sub abilities.
Also note that things such as proficiency score and languages known are considered to be "traits,"
and anything that gives spellcasting ability (from feats to subclasses to classes and on) are considered
"spellcastings" and should not be modeled as abilities.

## Ability JSON Structure
```json
{
    "name": "ability name",
    "description": "ability text",
    "hidden": false,
    "scaler": {
        "name": "scaler name",
        "scaling": "formula"
    },
    "charge_type": {
        "name": "charge name"
        "count": "formula",
        "recharge_hooks": ["long rest", "short rest", ...],
        "recharge_val": "formula"
    }
}
```

## Ability Fields
- `json_type`: this field must be "ABILITY"
- `name`: the name of the ability
- `description`: the description/flavor text of the ability
- `hidden`: whether or not the frontend will show this by default
- `scaler`: a scaling portion of the ability. For example, Monk's martial arts die.
    - `name`: name of the scaling portion
    - `scaling`: a math formula for how it will scale
- `charge_type`: the charges for an ability. For example, a wish stone has 3 charges
    - `name`: name of the charge
    - `count`: a math formula for how many charges the player has at maximum
    - `recharge_hooks`: events/hooks that the ability triggers on. For example: dawn, long rest, level up
    - `recharge_val`: a mathematical formula for how much the player recharges on hooks

## Related Links
- [Feature](features/Feature.md)
- [Trait](features/TraitModification.md)
