# Trapping Rain Water — Left Wall + Right Scan

## Approach

The idea is to treat each position as a potential left wall and scan to the right looking for a suitable right wall.

For a left wall at index `left`, search for the first wall on the right whose height is greater than or equal to the left wall:

```text
height[right] >= height[left]
```

If such a wall is found, it can safely close the basin.

The water level is:

```text
waterLevel = min(height[left], height[right])
```

Then calculate the water trapped between the two walls.

If no wall on the right is tall enough, keep track of the tallest wall encountered. Once the end of the array is reached, that tallest wall becomes the best possible right boundary for the remaining basin.

After calculating a basin, the right boundary becomes the new left boundary and the process continues.

## Calculating a Well

The water trapped between two walls can be calculated by checking every element between them.

For:

```text
left wall = 2
right wall = 3

2  1  0  1  3
```

The water level is:

```text
min(2, 3) = 2
```

Therefore:

```text
water = (2 - 1) + (2 - 0) + (2 - 1)
      = 1 + 2 + 1
      = 4
```

The helper function performs this calculation:

```cpp
int calcWell(vector<int>& height, int left, int right) {
    int waterLevel = min(height[left], height[right]);
    int water = 0;

    for (int i = left + 1; i < right; i++) {
        water += waterLevel - height[i];
    }

    return water;
}
```

## Finding the Right Wall

For each `left` position, scan to the right.

If:

```text
height[right] >= height[left]
```

then the basin can be closed immediately.

For example:

```text
2  1  0  1  3
^           ^
L           R
```

Since:

```text
3 >= 2
```

the water level is limited by the left wall:

```text
waterLevel = 2
```

After calculating the basin, `right` becomes the new `left`.

## When No Suitable Right Wall Exists

Consider:

```text
5  2  0  3  1  4
^
L
```

There is no wall on the right with height greater than or equal to `5`.

In this case, the algorithm keeps track of the tallest wall encountered:

```text
2, 0, 3, 1, 4
```

The tallest is `4`.

Therefore, the best possible right boundary is `4`, giving:

```text
waterLevel = min(5, 4)
            = 4
```

This allows the remaining basin to be calculated instead of discarded.

## Why This Works

For a basin to trap water, it needs two boundaries.

The water level is always determined by the shorter boundary:

```text
min(leftWall, rightWall)
```

When a right wall reaches or exceeds the height of the left wall, the left wall is guaranteed to be the limiting boundary, so the basin can be finalized.

If no such wall exists, the tallest right-side wall gives the highest possible water level for that remaining section.

After processing a basin, its right wall becomes the next candidate left wall.

## Example

Consider:

```text
height = [2, 1, 0, 1, 3]
```

Start with:

```text
left = 0
height[left] = 2
```

Scan right:

```text
2  1  0  1  3
^           ^
L           R
```

The wall at height `3` satisfies:

```text
3 >= 2
```

So calculate:

```text
waterLevel = min(2, 3) = 2
```

Interior heights:

```text
1, 0, 1
```

Water:

```text
(2 - 1) + (2 - 0) + (2 - 1)
= 4
```

Then the right wall becomes the new left wall.

## Complexity

The algorithm may scan a large portion of the remaining array for every new left wall.

Additionally, `calcWell()` scans the elements inside each discovered basin.

Therefore, in the worst case:

- **Time:** `O(n²)`
- **Auxiliary Space:** `O(1)`

The `height` array is the input and is not counted as auxiliary space.

## Brute Force → Left Wall + Right Scan

The brute-force approach considers every possible pair of walls.

This approach improves the reasoning by fixing a left wall and searching for a useful right boundary.

The key observation is:

> A right wall at least as tall as the left wall can immediately close the basin.

If such a wall does not exist, the tallest wall on the right is the best available boundary.

This reduces unnecessary pair checking, although the repeated right-side scans still make the worst-case complexity `O(n²)`.

## Key Learning

> **Before optimizing for time complexity, first find a way to decompose the problem into smaller, logically complete pieces.**

For this approach:

> **Fix a left wall, find the best usable right boundary, calculate the basin, then continue from that right boundary.**

This approach provides a useful stepping stone toward the optimal `O(n)` monotonic-stack solution.
