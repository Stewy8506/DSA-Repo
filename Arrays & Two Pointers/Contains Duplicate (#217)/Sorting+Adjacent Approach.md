# Contains Duplicate — Sorting + Adjacent Comparison

## Approach

Sort the array first. Once sorted, equal values are guaranteed to appear next to each other.

For example:

```text
[4, 1, 3, 4, 2]
        ↓
[1, 2, 3, 4, 4]
```

After sorting, traverse the array from the second element onward and compare each element with the previous element.

If:

```text
nums[i] == nums[i - 1]
```

a duplicate exists.

If the entire array is traversed without finding equal adjacent values, there are no duplicates.

## Why It Works

Sorting changes the order of the elements but does not change which values exist.

Therefore, if a value occurs more than once, all of its occurrences become consecutive after sorting.

This means checking only adjacent elements is sufficient.

## Complexity

- **Time:** `O(n log n)` due to sorting.
- **Auxiliary Space:** `O(1)` 

*aside from implementation-dependent stack space used by `std::sort`.

## Why Use This Approach?

The main advantage is low additional memory usage.

Compared with a hash-set solution, this approach trades some asymptotic time efficiency for significantly less auxiliary storage.

It is also simple and uses the highly optimized standard-library `sort`.

## Key Learning

A useful pattern is:

> **Transform the data into an ordered form so that a global property becomes locally detectable.**

Here, sorting transforms:

```text
"Does any value appear more than once?"
```

into:

```text
"Are any adjacent values equal?"
```
