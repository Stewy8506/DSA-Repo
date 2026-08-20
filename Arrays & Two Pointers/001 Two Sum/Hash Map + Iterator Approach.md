# Two Sum — Hash Map + Iterator

## Approach

Traverse the array once while maintaining a hash map that stores:

```text
number → index where it was previously seen
```

For each `nums[i]`, calculate the value needed to reach the target:

```text
needed = target - nums[i]
```

Before inserting the current number into the map, search for `needed`.

If it already exists, the stored index and the current index form the required pair.

If it does not exist, store the current number and its index for future elements.

The current element is checked **before** being inserted. This is important because it prevents an element from being paired with itself and correctly handles duplicate values.

## Why It Works

For every current value `nums[i]`, there is only one value that can form the target with it:

```text
target - nums[i]
```

If that complement has appeared earlier, its index is already stored in the hash map, so the solution can be returned immediately.

Checking before inserting also handles duplicates correctly.

For example:

```text
nums = [3, 3]
target = 6

i = 0
needed = 3
3 is not in the map
→ store 3 → 0

i = 1
needed = 3
3 is already in the map
→ pair found: indices 0 and 1
```

## Iterator Optimization

Instead of calling `find()` and then performing another lookup with `map[needed]`, use the iterator returned by `find()` directly.

The iterator provides access to:

```text
it->first   → key
it->second  → stored index
```

This means the stored index can be retrieved from the same lookup.

Conceptually:

```text
find needed
    ↓
not found → store current value
found     → use iterator's stored index
```

This avoids performing a second hash-table lookup for the same key.

## Complexity

- **Time:** `O(n)` average.
- **Auxiliary Space:** `O(n)` in the worst case.
- **Output Space:** `O(1)` because the result contains exactly two indices.

Hash-table operations such as `find` and insertion are `O(1)` on average, giving an overall average-case `O(n)` traversal.

## Why Use This Approach?

The array is unsorted, so the two-pointer technique used for Two Sum II cannot be applied directly without first sorting and preserving the original indices.

The hash map allows the required complement to be found in average `O(1)` time while preserving the original indices.

The iterator version is slightly cleaner and avoids a redundant second lookup after `find()`.

## Key Learning

> **When looking for a pair that satisfies a target relationship, store previously seen values so the required complement can be checked in constant average time.**

A second useful pattern is:

> **If a lookup operation already returns an iterator, use the iterator's stored value instead of performing another lookup for the same key.**
