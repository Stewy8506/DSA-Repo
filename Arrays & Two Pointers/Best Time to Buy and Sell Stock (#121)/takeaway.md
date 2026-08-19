# Best Time to Buy and Sell Stock

## Core Idea

The goal is to maximize:

`selling price - buying price`

with the constraint that the **buying day must come before the selling day**.

The important observation is:

> For any given selling day, we only care about the cheapest price that appeared before that day.

There is no reason to compare the current selling price against every previous price.

---

## Why the Brute-Force Approach Works but Is Not Good Enough

The obvious approach is to consider every possible pair of days:

- Choose a buying day.
- Choose every later selling day.
- Calculate the profit.
- Keep the maximum.

This correctly considers every valid transaction, but it takes:

**Time:** `O(n²)`

For large arrays, the number of comparisons becomes enormous, which can result in **Time Limit Exceeded**.

The key problem is that we repeatedly perform work that isn't necessary.

---

## The Key Observation

Suppose the current price is:

`prices[i]`

To get the maximum profit if we sell today, we want:

`prices[i] - minimum previous price`

We don't need to know every previous price.

We only need to remember:

- The **minimum price seen so far**
- The **maximum profit found so far**

This reduces the problem from checking every pair to processing each price exactly once.

---

## Why This Guarantees the Correct Answer

At every index `i`:

1. We know the minimum price among the days we've already encountered.
2. That minimum price represents the best possible buying price for selling on day `i`.
3. We calculate the best possible profit for selling today.
4. We compare it with the best profit we've found previously.
5. We continue to the next day.

Because we scan from left to right, the minimum price we're using always comes from a day **before or at the current day**.

Therefore, the buy-before-sell constraint is automatically respected.

---

## Why We Don't Just Find the Global Minimum

A tempting approach is:

1. Find the smallest price in the entire array.
2. Find the largest price after it.
3. Calculate the profit.

This doesn't always work because the global minimum might occur too late.

Example:

`[2, 10, 1, 3]`

The global minimum is `1`, but the best transaction is:

`2 → 10`

with a profit of `8`.

Therefore, we need to preserve the best profit found **before** a new minimum appears.

---

## State We Actually Need

Only two pieces of information are necessary:

### `minPrice`

The lowest price encountered so far.

### `maxProfit`

The highest valid profit encountered so far.

Everything else from the previous days can be discarded.

This is why the solution uses constant extra space.

---

## Why This Is the Best Approach

The problem requires examining the prices because any day could potentially be the best buying or selling day.

A single left-to-right traversal is sufficient.

Therefore:

**Time:** `O(n)`

**Space:** `O(1)`

You cannot asymptotically improve the time below `O(n)` because you need to inspect the input to know whether a better opportunity exists.

So `O(n)` time and `O(1)` extra space is optimal.

---

## Example

For:

`[7, 1, 5, 3, 6, 4]`

The important state evolves like this:

| Price | Minimum Seen | Best Profit |
|---:|---:|---:|
| 7 | 7 | 0 |
| 1 | 1 | 0 |
| 5 | 1 | 4 |
| 3 | 1 | 4 |
| 6 | 1 | 5 |
| 4 | 1 | 5 |

The answer is `5`.

The transaction is:

`Buy at 1 → Sell at 6`

---

## Important Edge Case

For a decreasing array:

`[7, 6, 5, 4, 3, 2, 1]`

every possible transaction loses money.

Therefore the maximum profit remains:

`0`

This correctly represents the fact that the best decision is to make no transaction.

---

## What I Should Remember

### Pattern

When repeatedly calculating:

`current value - previous value`

ask:

> "Which property of all previous values actually matters?"

Here, only the **minimum previous value** matters.

### General Optimization Pattern

Instead of storing or repeatedly searching the entire history:

`Entire history → useful summary → constant-size state`

This is a useful pattern far beyond this particular problem.

### Final Insight

> **For every possible selling day, the only previous information that matters is the cheapest price seen so far.**