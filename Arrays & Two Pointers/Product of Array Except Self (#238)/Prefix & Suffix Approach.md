# Product of Array Except Self — Prefix + Suffix Products

## Approach

For every index `i`, the required result is:

```text
(product of everything to the left of i)
×
(product of everything to the right of i)
```

The brute-force approach recalculates these products for every index. Instead, calculate the prefix and suffix products incrementally.

### First Pass — Prefix Products

Traverse from left to right while maintaining the product of all elements seen before the current index.

Store this prefix product directly in `answer[i]`.

For example:

```text
nums:
[1, 2, 3, 4]

after the prefix pass:
[1, 1, 2, 6]
```

The value at each position represents the product of everything to its left.

The running product is updated only **after** storing the current prefix, so `nums[i]` itself is excluded.

### Second Pass — Suffix Products

Traverse from right to left while maintaining the product of all elements seen after the current index.

Multiply this running suffix product into the existing value in `answer[i]`.

For example:

```text
prefix products:
[1, 1, 2, 6]

after the suffix pass:
[24, 12, 8, 6]
```

The output array therefore becomes the product of the prefix and suffix for every index.

## Why It Works

Every element other than `nums[i]` is either:

- to the left of `i`, or
- to the right of `i`.

The first pass calculates the complete left-side product for every index.

The second pass calculates the complete right-side product and combines it with the already stored left-side product.

No element at index `i` is included in either side.

Zeros are handled automatically because they simply become part of the relevant prefix or suffix product. No special zero-count logic is required.

## Why No Division Is Needed

The approach never calculates the product of the entire array and then removes `nums[i]`.

Instead, it directly constructs the exact product needed for each position:

```text
left product × right product
```

Therefore, division is unnecessary.

## Complexity

- **Time:** `O(n)` — two independent linear passes.
- **Auxiliary Space:** `O(1)` — only the two running products require additional storage.
- **Output Space:** `O(n)` — the required `answer` array.

The output array is reused to store the prefix products, so no separate prefix or suffix arrays are needed.

## Why Use This Approach?

This is the optimal approach for the problem under the given constraints.

Compared with the brute-force approach, it eliminates repeated product calculations.

Compared with the total-product + zero-count approach, it avoids division and special-case handling for zeros.

It also uses only constant auxiliary memory by storing the prefix products directly in the output array.

## Key Learning

> **When multiple outputs require overlapping calculations, compute the shared information incrementally and reuse it instead of recalculating it.**

The crucial observation is:

```text
answer[i] = left product × right product
```

Once this is recognized, two directional passes are enough to solve the problem in linear time.
