# Product of Array Except Self — Brute Force

## Approach

For every index `i`, calculate the product of every element except `nums[i]`.

For each index:
- Multiply all elements to the right of `i`.
- Multiply all elements to the left of `i`.
- Store the resulting product at `answer[i]`.

The element at index `i` is therefore excluded from both products.

## Why It Works

Every element other than `nums[i]` is either to the left or right of `i`.

By multiplying both sides independently, the product of every element except the current one is obtained.

For example:

```text
[1, 2, 3, 4]

For index 2:
1 × 2 × 4 = 8
```

## Complexity

- **Time:** `O(n²)` because every index requires traversing the elements around it.
- **Auxiliary Space:** `O(1)`
- **Output Space:** `O(n)`

## Why It Fails the Constraints

Although the approach is logically correct, the nested loops make it `O(n²)`.

With `n` up to `10⁵`, the number of operations becomes too large, so this approach will not pass the time constraints.

## Why Use This Approach?

It is useful as a first solution because the logic directly follows the definition of the problem.

It establishes a correct baseline before looking for repeated work that can be eliminated.

## Key Learning

A brute-force solution is often valuable even when it cannot pass.

> **First derive a correct solution directly from the problem. Then identify what work is being repeated and optimize it.**
