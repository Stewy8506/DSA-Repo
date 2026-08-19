# Best Time to Buy and Sell Stock

## 1. Problem

Given an array `prices` where `prices[i]` represents the stock price on day `i`, find the maximum profit that can be achieved by:

- Buying on one day.
- Selling on a **later** day.

If no profitable transaction exists, return `0`.

---

## 2. Core Insight

For a fixed selling day `i`, the profit is:

```text
profit = prices[i] - buying_price
```

To maximize this profit, we want the **smallest buying price among all previous days**.

Therefore, while traversing the array from left to right, we only need to maintain:

- `minPrice` — the lowest price seen so far.
- `maxProfit` — the highest profit found so far.

We do **not** need to remember every previous price.

---

## 3. Why Brute Force Is Not Enough

The straightforward approach is to consider every valid pair of days:

```text
buy day < sell day
```

This requires checking approximately:

```text
n(n - 1) / 2
```

pairs.

### Complexity

```text
Time:  O(n²)
Space: O(1)
```

Although this approach is logically correct, it becomes too slow for large input arrays and can result in **Time Limit Exceeded**.

The problem is repeated work: for every selling day, we repeatedly examine all previous prices.

---

## 4. Optimal Approach

Process the array once from left to right.

Maintain two values:

| Variable | Meaning |
|---|---|
| `minPrice` | Lowest price encountered so far |
| `maxProfit` | Highest valid profit encountered so far |

For every price:

1. Update `minPrice` if the current price is smaller.
2. Calculate the profit obtained by selling at the current price using `minPrice`.
3. Update `maxProfit` if this profit is larger.

The implementation is stored separately in the solution file. The important part to remember is the state being maintained.

---

## 5. Why It Works

Consider a selling day `i`.

Every possible buying day before `i` produces:

```text
prices[i] - prices[k]
```

To maximize this expression, we need the smallest possible `prices[k]`.

Therefore:

```text
best profit for day i
=
prices[i] - minimum previous price
```

Instead of searching for that minimum repeatedly, we maintain it as we traverse the array.

This means every selling day can be evaluated in `O(1)` time.

---

## 6. The Ordering Constraint

The problem requires:

```text
buy day < sell day
```

The left-to-right traversal handles this automatically.

When processing `prices[i]`, `minPrice` represents a price encountered earlier in the traversal.

Therefore, the algorithm never accidentally chooses a buying day after the selling day.

This is an important reason why the traversal direction matters.

---

## 7. Example

Consider:

```text
prices = [7, 1, 5, 3, 6, 4]
```

Track the state as we traverse:

| Day | Price | Minimum Price So Far | Profit If Sold Today | Maximum Profit |
|---:|---:|---:|---:|---:|
| 0 | 7 | 7 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 |
| 2 | 5 | 1 | 4 | 4 |
| 3 | 3 | 1 | 2 | 4 |
| 4 | 6 | 1 | 5 | 5 |
| 5 | 4 | 1 | 3 | 5 |

The maximum profit is:

```text
5
```

achieved by:

```text
Buy at 1
Sell at 6
```

---

## 8. Why We Cannot Simply Find the Global Minimum

A tempting approach is:

1. Find the smallest price in the entire array.
2. Find the largest price after it.
3. Calculate the profit.

This fails because the global minimum may occur too late.

Example:

```text
[2, 10, 1, 3]
```

The global minimum is `1`, but it appears after the best selling opportunity.

The optimal transaction is:

```text
Buy at 2
Sell at 10
Profit = 8
```

Therefore, we need to continuously track the best opportunity seen so far rather than committing to one global minimum.

---

## 9. Important Edge Case

Consider a completely decreasing array:

```text
[7, 6, 5, 4, 3, 2, 1]
```

Every possible transaction results in a loss.

Since making no transaction is allowed, the answer is:

```text
0
```

This is why `maxProfit` starts at `0`.

---

## 10. Complexity

### Time

```text
O(n)
```

The array is traversed exactly once.

### Space

```text
O(1)
```

Only a constant number of variables are maintained regardless of the input size.

---

## 11. Why This Is Optimal

An `O(n)` solution is asymptotically optimal.

The algorithm must inspect the prices because any element could potentially be:

- The minimum buying price.
- The maximum selling price.
- Part of the optimal transaction.

Therefore, we cannot generally solve the problem in less than `O(n)` time.

The final complexity is:

```text
Time:  O(n)
Space: O(1)
```

---

## 12. Key Learning

The most important lesson is **not** the specific code.

The important reasoning pattern is:

> When repeatedly comparing the current value against every previous value, ask whether all previous values can be represented by a smaller summary.

Here:

```text
All previous prices
        ↓
Only the minimum previous price matters
        ↓
Maintain that minimum
        ↓
One pass through the array
        ↓
O(n) time, O(1) space
```

### Pattern to Remember

When a problem repeatedly asks for the best result involving the current element and **any previous element**, look for a property of the previous elements that can be maintained incrementally.

Common examples include:

- Minimum so far
- Maximum so far
- Prefix sum
- Frequency/count
- Running state

The goal is to replace repeated searching with a **running summary of the past**.
