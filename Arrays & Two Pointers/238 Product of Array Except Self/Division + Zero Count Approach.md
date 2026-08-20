# Product of Array Except Self — Total Product + Zero Count

## Approach

Instead of calculating the product separately for every index, calculate the product of all **non-zero** elements once.

At the same time, keep track of:

- How many zeros are present.
- The index of the zero, when there is one.

The answer can then be determined from the number of zeros.

### Case 1 — No zeros

If there are no zeros, the product of all elements is available.

For each index:

```text
answer[i] = total product / nums[i]
```

### Case 2 — Exactly one zero

The product of all non-zero elements is the answer at the zero's index.

Every other position has a zero in its product, so its answer is `0`.

For example:

```text
[1, 2, 0, 4]

answer:
[0, 0, 8, 0]
```

### Case 3 — Two or more zeros

Every answer is `0`.

Even after excluding one element, at least one zero remains in every product.

## Why It Works

The only obstacle to dividing the total product by `nums[i]` is the presence of zero.

By counting zeros separately and excluding them from the accumulated product, all possible zero cases can be handled explicitly.

When there are no zeros, division directly removes the contribution of `nums[i]`.

When zeros exist, the zero count tells us exactly which positions can have a non-zero result.

## Complexity

- **Time:** `O(n)` — two linear passes through the array.
- **Auxiliary Space:** `O(1)` — only a constant number of variables are used.
- **Output Space:** `O(n)`.

## Why Use This Approach?

This approach reduces the brute-force solution from `O(n²)` to `O(n)` while keeping auxiliary memory constant.

It also demonstrates that a problem that appears to require calculating many separate products can sometimes be solved by calculating shared information once and reusing it.

The tradeoff is that the solution requires explicit zero handling and uses division.

## Key Learning

> **Look for information that is common to multiple outputs and calculate it once instead of repeatedly recalculating it.**

Here, the total product of the non-zero elements is shared across the answers, while the number and position of zeros determine how that information can be used.
