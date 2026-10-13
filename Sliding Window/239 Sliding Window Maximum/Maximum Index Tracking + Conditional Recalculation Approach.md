# Sliding Window Maximum — Maximum Index Tracking + Conditional Recalculation

## Problem

Given an integer array `nums` and an integer `k`, return an array containing the maximum value in every contiguous sliding window of size `k`.

## Approach

Use a **sliding window** with two boundaries, `left` and `right`, and track both the current maximum value (`maxval`) and its index (`maxidx`).

Instead of recalculating the maximum for every window, recalculate it only when the current maximum leaves the window.

For each new window:

1. Check whether `maxidx` is left of the new window. If so, find the maximum in the new window using `max_element()`.
2. Compare the incoming element with `maxval`. If it is larger, update both `maxval` and `maxidx`.
3. Append `maxval` to the output.
4. Move the window one position to the right.

The first window is handled separately by finding the maximum among the first `k` elements.

## Key Observation

The maximum does not need to be recalculated while its index remains inside the current window. However, when that index leaves, the algorithm must scan the remaining window to find the next maximum.

This reduces unnecessary scans compared with recalculating the maximum for every window, but a scan can still take `O(k)` time.

## Implementation

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 1, right = k;
        int maxval = *max_element(nums.begin(), nums.begin() + k);
        int maxidx = max_element(nums.begin(), nums.begin() + k) - nums.begin();

        vector<int> out;
        out.push_back(maxval);

        while (right < nums.size()) {
            if (left > maxidx) {
                maxidx = max_element(
                    nums.begin() + left,
                    nums.begin() + right + 1
                ) - nums.begin();

                maxval = *max_element(
                    nums.begin() + left,
                    nums.begin() + right + 1
                );
            }

            if (nums[right] > maxval) {
                maxidx = right;
                maxval = nums[right];
            }

            out.push_back(maxval);
            left++;
            right++;
        }

        return out;
    }
};
```

## Why It Works

Initially, the algorithm finds the maximum in the first window, covering indices `0` through `k - 1`.

The next window covers indices `left` through `right`, inclusive. If `maxidx` is smaller than `left`, the previous maximum has left the window, so the algorithm scans the current window to find a replacement.

The range passed to `max_element()` must use `nums.begin() + right + 1` as its end iterator because the end iterator is exclusive. This includes the element at index `right`.

After handling an expired maximum, the algorithm checks whether the incoming element is larger than the current maximum. If it is, both `maxval` and `maxidx` are updated. Finally, the current maximum is appended to `out`.

## Complexity

- **Time:** `O(nk)` in the worst case. Recalculating the maximum can scan up to `k` elements for each window.
- **Auxiliary space:** `O(1)`, excluding the output array.

Here, `n` is the length of `nums`, and `k` is the window size.

## Limitations

This approach can be faster than the basic brute-force method on some inputs because it avoids rescanning the window while the current maximum remains inside it. However, when the maximum repeatedly leaves the window, repeated scans can still make the worst-case time complexity `O(nk)`.

It also calls `max_element()` twice when recalculating: once to obtain the index and once to obtain the value. This can be reduced to one call by storing the returned iterator and using it for both.

## Key Learning

> **Tracking the maximum's index avoids recalculating the maximum until that element leaves the window, but it does not eliminate repeated scans.**

The next optimization is a **monotonic deque**, which maintains candidate maximums and solves the problem in `O(n)` time.
