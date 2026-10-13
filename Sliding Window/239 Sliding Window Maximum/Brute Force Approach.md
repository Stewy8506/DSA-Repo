# Sliding Window Maximum — Brute Force Approach

## Problem

Given an integer array `nums` and an integer `k`, return an array containing the maximum value in every contiguous sliding window of size `k`.

## Approach

Use a **sliding window** of fixed size `k`. Move the window one position to the right at a time and find the maximum element in each window.

For each starting index `i`:

1. Create an empty `window` vector.
2. Copy the `k` elements from `nums[i]` through `nums[i + k - 1]` into `window`.
3. Use `max_element()` to find the largest element in the window.
4. Append that maximum to `out`.
5. Increment `i` to process the next window.

The loop continues while:

```cpp
i + k <= nums.size()
```

The `<=` ensures that the final valid window is processed.

## Key Observation

Every window overlaps with the next window in `k - 1` elements, but the brute-force approach ignores this overlap. It rebuilds the window and scans all `k` elements to find the maximum each time.

For an array of length `n`, the number of windows is:

```text
n - k + 1
```

## Implementation

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        int i = 0, currmax;

        while (i + k <= nums.size()) {
            vector<int> window;

            for (int j = i; j < i + k; j++) {
                window.push_back(nums[j]);
            }

            currmax = *max_element(window.begin(), window.end());
            out.push_back(currmax);
            i++;
        }

        return out;
    }
};
```

## Why It Works

The inner `for` loop copies exactly `k` elements into `window`, beginning at index `i`.

`max_element(window.begin(), window.end())` returns an iterator pointing to the largest element. The `*` dereferences that iterator to obtain the integer value:

```cpp
currmax = *max_element(window.begin(), window.end());
```

The maximum is appended to `out`, and `i` advances by one so the next window is processed. The loop stops once there are fewer than `k` elements remaining.

## Why It Can Get Time Limit Exceeded

There are `n - k + 1` windows. For each window, the algorithm copies `k` elements and scans those `k` elements to find the maximum.

Therefore, the total time complexity is:

```text
O((n - k + 1) * k) = O(nk)
```

When both `n` and `k` are large, this performs too much repeated work. For example, with `n = 100000` and `k = 50000`, there are `50001` windows, requiring roughly `2.5 billion` element visits just to examine the windows.

The extra `window` vector also uses `O(k)` auxiliary space.

## Complexity

- **Time:** `O((n - k + 1) * k)`, commonly expressed as `O(nk)`.
- **Auxiliary space:** `O(k)` for the temporary `window` vector, excluding the output array.

Here, `n` is the length of `nums`, and `k` is the window size.

## Key Learning

> **Brute force is a useful baseline, but overlapping sliding windows often repeat work. Look for a way to reuse information from the previous window.**

For this problem, the optimal monotonic deque approach runs in **`O(n)` time** by keeping only indices of elements that could still become the maximum.
