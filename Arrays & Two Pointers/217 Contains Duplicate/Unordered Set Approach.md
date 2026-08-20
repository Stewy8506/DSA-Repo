# Contains Duplicate — Unordered Set

## Approach

Traverse the array once while maintaining an `unordered_set` containing every value seen so far.

For each number:

1. Check whether it already exists in the set.
2. If it exists, a duplicate has been found.
3. Otherwise, insert it into the set and continue.

Conceptually:

```text
number already seen?
        │
   ┌────┴────┐
  yes        no
   │          │
duplicate    insert
```

## Why It Works

At any point in the traversal, the set contains exactly the values encountered earlier.

Therefore, if the current value is already present in the set, it must have appeared previously, meaning a duplicate exists.

There is no need to sort the array or compare every pair.

## Complexity

- **Time:** `O(n)` average case.
- **Space:** `O(n)`.

The `O(n)` time comes from performing an average `O(1)` hash lookup and insertion for each element.

## Why Use This Approach?

This is the asymptotically faster approach compared with sorting:

```text
Sorting:
O(n log n) time
O(1) auxiliary space

Hash set:
O(n) average time
O(n) space
```

The tradeoff is memory.

A hash table has additional overhead from buckets, hashing, allocations, and stored elements. Because of this, its measured runtime or memory usage can sometimes be worse than a highly optimized `std::sort` on a particular input or benchmark.

Big-O describes asymptotic scaling; it does not guarantee that an `O(n)` implementation will always be faster in a real benchmark.

## Key Learning

A useful pattern is:

> **When a problem asks whether something has appeared before, consider maintaining a set of previously seen values.**

This can replace sorting or repeated searching with a single traversal.

The broader pattern is:

```text
Previous elements
       ↓
Store the information needed for membership checks
       ↓
Process each new element once
       ↓
O(n) average time
```
