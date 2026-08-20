# Container With Most Water — Two Pointers

## Approach

The initial brute-force approach checks every possible pair of indices `(i, j)` and calculates the area of the container formed by them.

The area is:

```text
area = min(height[i], height[j]) × (j - i)
```

This guarantees the correct answer but takes `O(n²)` time because there are approximately `n² / 2` possible pairs.

The key to optimizing the solution is to recognize that not every pair needs to be checked.

Start with two pointers at the two ends of the array:

```text
left  →                         ←  right
```

Calculate the area between them and keep track of the maximum.

Then compare the two boundary heights.

- If `height[left] < height[right]`, move `left` inward.
- Otherwise, move `right` inward.

Continue until the pointers meet.

## Why Move the Shorter Side?

Suppose:

```text
height[left] < height[right]
```

The current container's height is therefore limited by `height[left]`.

Its area is:

```text
height[left] × (right - left)
```

Now consider moving the `right` pointer inward while keeping `left` fixed.

The width becomes smaller.

The new container height is:

```text
min(height[left], height[newRight])
```

Regardless of how tall `height[newRight]` is, it cannot exceed the fixed `height[left]` as the limiting height.

Therefore:

```text
new area ≤ height[left] × smaller width
```

which means it cannot be greater than the current area.

So when the left boundary is shorter, keeping it and moving the right boundary cannot produce a better container.

The same reasoning applies in reverse when the right boundary is shorter.

Therefore, the shorter boundary can safely be discarded.

## Why It Works

At every step, the algorithm considers the widest remaining container between `left` and `right`.

The shorter boundary determines the maximum possible height of that container.

Moving the taller boundary inward would:

1. Reduce the width.
2. Keep the shorter boundary unchanged.
3. Therefore keep the maximum possible height limited by the same shorter boundary.

So no better container can be obtained by moving the taller boundary.

Moving the shorter boundary is the only move that has a possibility of improving the area, because the new boundary may be taller.

This allows entire groups of candidate pairs to be discarded without explicitly checking them.

## Equal Heights

If:

```text
height[left] == height[right]
```

either pointer can be moved.

The implementation moves the `right` pointer through the `else` branch.

The current height is the same on both sides, so discarding either boundary is safe.

## Complexity

Each pointer only moves inward.

Neither pointer ever moves backward, so the total number of pointer movements is at most `n`.

- **Time:** `O(n)`
- **Auxiliary Space:** `O(1)`

The `height` array itself is the input and is not counted as auxiliary space.

## Brute Force → Two Pointers

The brute-force solution asks:

> "Which of all possible pairs gives the maximum area?"

The optimized solution asks:

> "Which pairs can I prove cannot possibly be better?"

The crucial observation is that the shorter boundary is the limiting factor.

Once the shorter boundary is identified, the taller boundary can be retained while the shorter one is moved inward.

This eliminates many candidate pairs at once and reduces the complexity from:

```text
O(n²) → O(n)
```

## Key Learning

> **Optimization often comes from proving that certain candidates can be safely discarded, rather than simply finding a faster way to evaluate every candidate.**

For this problem:

> **The shorter boundary limits the container's height. Moving the taller boundary inward only reduces width while keeping the same limiting height, so the taller boundary can be discarded instead.**

This is the core reasoning behind the two-pointer technique.