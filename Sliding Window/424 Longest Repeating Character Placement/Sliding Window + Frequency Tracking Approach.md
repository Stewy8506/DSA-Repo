# Longest Repeating Character Replacement — Sliding Window + Fixed Frequency Array

## Problem

Given a string `s` containing only uppercase English letters and an integer `k`, find the length of the longest substring that can be made of one repeated character by replacing at most `k` characters.

## Approach

Use a **sliding window** with two pointers, `left` and `right`, and a fixed-size frequency array.

```cpp
int freq[26] = {};
```

Each array index represents a letter:

- `freq[0]` stores the count of `'A'`.
- `freq[1]` stores the count of `'B'`.
- ...
- `freq[25]` stores the count of `'Z'`.

Convert an uppercase character into its array index with:

```cpp
s[right] - 'A'
```

For each character at `right`:

1. Add the character to the frequency array.
2. Update `maxFreq`, the highest frequency encountered so far.
3. If the window needs more than `k` replacements, move `left` forward by one and decrement the frequency of the character leaving the window.
4. Update `ans` with the largest window length found.

## Key Observation

To make every character in a window identical, keep the most frequent character and replace all the others.

Therefore:

```text
replacements needed = window length - maxFreq
```

The window condition is:

```cpp
(right - left + 1) - maxFreq <= k
```

If the expression exceeds `k`, the window is too large for the available replacements.

## Implementation

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int left = 0, ans = 0, maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

## Why It Works

The window expands as `right` moves forward. The frequency array tracks how many times each character appears in the current window.

`maxFreq` stores the largest character frequency encountered during the scan. In this optimized solution, `maxFreq` is deliberately **not decreased** when the left side of the window moves forward.

When the window length minus `maxFreq` exceeds `k`, the algorithm advances `left` by one. It decrements the frequency of the character leaving the window **before** incrementing `left`, so the frequency array stays synchronized with the window.

Although the retained `maxFreq` may be greater than the true maximum frequency in the current window, this optimization still yields the correct maximum length. The algorithm does not need to reconstruct the exact best character or maintain an exactly valid window at every intermediate step.

## Why Use `if` Instead of `while`?

A `while` loop can shrink the window repeatedly until the condition is satisfied according to the tracked `maxFreq`. However, the standard optimized solution can use `if` and shrink by only one position per iteration.

This works because the goal is to find the **maximum achievable length**, not to ensure that every intermediate window is exactly valid. The window's maximum length does not need to decrease during the scan.

Both approaches run in linear time, but `if` is sufficient for this optimized pattern.

## Complexity

- **Time:** `O(n)` — each character is processed by `right` once, and `left` only moves forward.
- **Auxiliary space:** `O(1)` — the frequency array always has 26 entries.

Here, `n` is the length of `s`.

## Key Learning

> **Use a sliding window when you need the longest contiguous substring that satisfies a condition, and maintain only the information needed to decide whether to expand or shrink the window.**

For this problem, the key formula is:

**Window length − highest character frequency = replacements needed.**

The `freq[26]` array provides constant-time character counts, while `maxFreq` avoids repeatedly scanning the whole array.
