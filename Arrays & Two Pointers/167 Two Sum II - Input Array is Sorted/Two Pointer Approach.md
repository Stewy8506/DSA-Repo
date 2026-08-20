# Two Sum II — Two Pointers on a Sorted Array

## Approach

The array is already sorted in ascending order, so use two pointers:

- `left` starts at the beginning.
- `right` starts at the end.

Calculate the sum of the two values at the pointers.

Then use the sorted property to decide which pointer to move:

- If `numbers[left] + numbers[right] < target`, the sum is too small, so move `left` to the right to increase the sum.
- If `numbers[left] + numbers[right] > target`, the sum is too large, so move `right` to the left to decrease the sum.
- If the sum equals `target`, the required pair has been found.

Continue until the pointers meet.

The problem uses 1-based indexing for the answer, so the final indices are converted from C++'s 0-based indexing.

## Why It Works

Because the array is sorted, moving either pointer has a predictable effect on the sum.

If the current sum is too small, moving `right` left would only make the sum smaller, so the only useful move is to increase `left`.

Similarly, if the current sum is too large, moving `left` right would only make the sum larger, so the only useful move is to decrease `right`.

Therefore, every pointer movement eliminates impossible pairs without needing to search them individually.

Since the problem guarantees exactly one solution, the matching pair will be found before the pointers cross.

## Complexity

- **Time:** `O(n)` because each pointer moves through the array at most once.
- **Auxiliary Space:** `O(1)`
- **Output Space:** `O(1)` because the result always contains exactly two indices.

## Why Use This Approach?

A brute-force approach would examine pairs repeatedly and take `O(n²)` time.

The sorted property allows the two-pointer approach to eliminate large groups of impossible pairs with every pointer movement.

Compared with using a hash table, this approach achieves linear time without requiring `O(n)` additional memory.

The result is both time-efficient and memory-efficient.

## Key Learning

> **A sorted array can turn a search problem into a directional two-pointer problem.**

When the current value is too small, move toward larger values.

When it is too large, move toward smaller values.

The important pattern is to use the ordering of the data to eliminate impossible candidates instead of searching through them individually.
