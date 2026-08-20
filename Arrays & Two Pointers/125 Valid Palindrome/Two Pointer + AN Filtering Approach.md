# Valid Palindrome — Two Pointers + Alphanumeric Filtering

## Approach

Use two pointers, one starting at the beginning of the string and one at the end.

Move the left pointer forward until it reaches an alphanumeric character, and move the right pointer backward until it reaches an alphanumeric character.

Then compare the two characters without considering letter case.

If they differ, the string is not a palindrome.

If they match, move both pointers inward and continue until they meet or cross.

This avoids creating a separate cleaned string.

## Why It Works

A palindrome reads the same from both directions.

Therefore, after ignoring non-alphanumeric characters, the character at the left side must match the corresponding character at the right side.

The two-pointer traversal checks exactly these corresponding pairs.

Non-alphanumeric characters can be skipped because they do not contribute to the palindrome according to the problem definition.

Case normalization ensures that uppercase and lowercase versions of the same letter are treated as equal.

If every corresponding pair matches, the string is a palindrome.

## Complexity

- **Time:** `O(n)` because each pointer moves through the string at most once.
- **Auxiliary Space:** `O(1)`

No cleaned or reversed copy of the string is created.

## Why Use This Approach?

The two-pointer approach is both time- and space-efficient.

A straightforward alternative would be to create a new string containing only alphanumeric characters, normalize its case, and then compare it with its reverse.

That would require `O(n)` additional memory.

The two-pointer approach performs the same logical filtering and comparison directly on the original string, reducing auxiliary space to `O(1)`.

## Key Learning

> **When a problem compares elements symmetrically from both ends, consider two pointers moving toward the center.**

The important optimization is to process the input directly rather than constructing a transformed copy of it.
