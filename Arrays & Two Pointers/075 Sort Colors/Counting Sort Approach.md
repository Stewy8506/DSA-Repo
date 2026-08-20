# Sort Colors — Counting Sort

## Approach

Use **frequency counting** to count how many `0`s, `1`s, and `2`s are present.

Since the array can only contain three possible values:

- Count the number of `0`s.
- Count the number of `1`s.
- The remaining elements must be `2`s.

Then make a second pass through the array and reconstruct it:

1. Place all the `0`s first.
2. Place all the `1`s next.
3. Fill the remaining positions with `2`s.

For example:

```text
nums = [2, 0, 2, 1, 1, 0]

Counts:
0 → 2
1 → 2
2 → 2

Reconstruct:

[0, 0, 1, 1, 2, 2]
```

## Why It Works

Every element belongs to exactly one of the three categories: `0`, `1`, or `2`.

Once we know the frequency of `0` and `1`, the number of `2`s is automatically determined:

```text
number of 2s = n - number of 0s - number of 1s
```

Therefore, placing the values in frequency order produces the sorted array.

## Key Idea

This is a specialized form of **Counting Sort**.

Instead of comparing elements with each other, we exploit the fact that the input has a very small, fixed range of possible values.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`
- **Passes:** 2

The first pass counts the frequencies and the second pass reconstructs the array. Since both passes are linear, the total time is `O(n)`.

## Why Use This Approach?

This is a simple and efficient solution when the range of possible values is very small.

For this problem, it is particularly clean because there are only three possible values.

The **Dutch National Flag** algorithm can also solve the problem in `O(n)` time and `O(1)` space, but it does so in a single pass. This counting approach is easier to understand and is still asymptotically optimal.

## Key Learning

When an array contains values from a **small, known range**, consider **frequency counting / Counting Sort** instead of comparison-based sorting.
