# Formula
Sometimes, it is necessary to use a mathematical formula to represent a value. 
Consider, for example, an ability that gives you charges (like ki points) equal
to 2 times your player level plus 5. To achieve this, you use a formula and keywords.
Keywords are indicated with square brackets and a case-sensative string. For example,
`[PROF]` will reference proficiency bonus, and return a value. A keyword can reference
any trait. See list of reserved keywords.

### Format
Formulas must be a string with no spaces, terms must
be connected by an addition sign (`+`) or a subtraction sign (`-`), and products must be
connected by a multiplication sign (`*`). Parentheses are not
permitted. The set of allowed characters is addition sign,
multiplicaiton sign, all numbers, and substrings in the form
of a keyword.


Valid example: `"3*[CHAR-BONUS]+2"` \
Valid example: `"3+2-1+[LEVEL]*2*[INT-BONUS]` \
Valid example: `5` \
Invalid example: `"3[CHAR-BONUS]` \
Invalid example: `1.5` \
Invalid example: `3x2` \
Invalid example: `2^[LEVEL]` \
Invalid example: `1.5*2`

### Debugging notes
If a keyword is not found, it will return 0. The formula must contain only integers.


## Related Links
- [Trait](json/features/TraitModification.md)
- [Keywords](ReservedKeywords.md)
