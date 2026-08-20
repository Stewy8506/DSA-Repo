# Sort Colors — Dutch National Flag

## Approach

Use the **Dutch National Flag algorithm** to partition the array into three regions:

```text
[ 0s ][ 1s ][ Unknown ][ 2s ]
  ↑              ↑          ↑
 low            mid        high
```

Maintain three pointers:

- `low` → position where the next `0` should go.
- `mid` → current element being examined.
- `high` → position where the next `2` should go.

Initially:

```text
low = 0
mid = 0
high = n - 1
```

Process elements while `mid <= high`.

### Case 1: `nums[mid] == 0`

Swap the current element with `nums[low]`.

Then:

```text
low++
mid++
```

The `0` is now in its correct region, and the element moved into `mid` is already known to belong to the processed region.

### Case 2: `nums[mid] == 1`

`1` belongs in the middle region, so simply:

```text
mid++
```

### Case 3: `nums[mid] == 2`

Swap the current element with `nums[high]`.

Then:

```text
high--
```

**Do not increment `mid`.**

The element moved from `high` into `mid` has not been examined yet, so it must be processed again.

## Why It Works

At every point, the array is divided into four regions:

```text
[ 0s ][ 1s ][ Unknown ][ 2s ]
```

The algorithm continuously shrinks the `Unknown` region.

- `low` separates `0`s from `1`s.
- `mid` separates processed elements from unknown elements.
- `high` separates unknown elements from `2`s.

When `mid > high`, there are no unknown elements remaining, so the entire array is sorted.

## Key Idea

The algorithm performs **in-place three-way partitioning**.

Instead of counting the elements first, it places each element directly into its appropriate region while traversing the array.

The critical detail is that when a `2` is encountered, `mid` does not move because the swapped-in element from the right side is still unknown.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`
- **Passes:** 1

Each element is processed a constant number of times, and only three pointers are used.

## Why Use This Approach?

This is the classic solution for #75 because it:

- Sorts the array in-place.
- Uses constant extra space.
- Requires only one traversal.
- Demonstrates the important **three-pointer / partitioning** technique.

Compared with the Counting Sort approach, both have `O(n)` time and `O(1)` space. The Dutch National Flag approach performs the sorting in a single traversal rather than counting first and reconstructing the array.

## Key Learning

When an array contains **three categories of values**, consider using **three-way partitioning** with pointers representing the boundaries of each region.

The most important pattern to remember is:

```text
0 → swap left, move both
1 → move mid
2 → swap right, move only right
```
