# Longest Substring Without Repeating Characters — Sliding Window + Fixed Array

## Approach

Use a **sliding window** defined by two pointers, `left` and `right`.

The window represents the current substring being considered. The goal is to keep this window free of duplicate characters while expanding it from left to right.

A **fixed-size integer array**, `last[128]`, stores the **most recent index** at which each ASCII character appeared. Each element is initialized to `-1`, indicating that the character has not appeared before.

For each character at `right`:

1. Read the current character, `c = s[right]`.
2. Check its most recent occurrence using `last[c]`.
3. Move `left` to `max(left, last[c] + 1)` so that it never moves backwards.
4. Update `last[c]` to the current `right`.
5. Calculate the current window length and update the maximum.
6. Move `right` forward.

For example, with:

```text
"abcabcbb"
```

The window grows as:

```text
[abc]
```

When the next `a` is encountered, its previous index was `0`, so `left` moves to `1`:

```text
a[bca]
```

The window is valid again, and the process continues.

The important observation is that the array lets us **jump directly past a duplicate** without removing characters one by one.

## Implementation

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        fill(last, last + 128, -1);

        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            left = max(left, last[c] + 1);
            last[c] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

**Note:** This implementation assumes ASCII input. For arbitrary byte values, use `int last[256]` and index it with `static_cast<unsigned char>(c)`. For general Unicode text, a different character-handling strategy is needed.

## Why It Works

The sliding window maintains the invariant that the substring from `left` through `right` contains no repeated characters.

When a duplicate is found, its previous index identifies where the conflict occurred. Moving `left` to `last[c] + 1` removes the previous occurrence from the window.

However, the previous occurrence may already be outside the current window. Therefore, `left` must only move forward:

```cpp
left = max(left, last[c] + 1);
```

After this adjustment, the window is valid again.

Because the array directly maps each character to its most recent position, lookups and updates take **O(1)** time. Each character is processed once by `right`, while `left` only moves forward.

## Complexity

- **Time:** `O(n)`
- **Auxiliary Space:** `O(1)` for a fixed-size array
- **Output Space:** `O(1)`

Here, `n` is the length of the input string. The array has a fixed size independent of `n`, assuming a fixed character set.

## Why Use This Approach?

This approach avoids repeatedly checking overlapping substrings.

The fixed array provides direct access to each character's previous position without the hashing overhead associated with `unordered_map`.

Compared with the hash map approach, it offers the same asymptotic time complexity but can be faster in practice because array indexing is simple and predictable.

The trade-off is that the array must cover the supported character set. A fixed array is particularly suitable when the input alphabet is small and known in advance.

## Key Learning

> **Combine a sliding window with a fixed array when a contiguous range must maintain a property and the input alphabet is bounded.**

A useful general pattern is:

**Right expands → detect duplicate → left jumps forward → restore validity → update maximum.**

The `max(left, last[c] + 1)` pattern is essential whenever a sliding-window boundary must never move backwards.

The broader lesson is that **choosing the right data structure can improve constant factors without changing the algorithm's time complexity**.