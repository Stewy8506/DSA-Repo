# Permutation in String — Frequency Array + Sliding Window

## Problem

Given two strings, `s1` and `s2`, return `true` if `s2` contains a substring that is a permutation of `s1`. Otherwise, return `false`.

A permutation contains exactly the same characters with the same frequencies, but the characters can appear in any order.

For example, `"ab"` and `"ba"` are permutations of each other because both contain one `a` and one `b`.

## Approach

Use **two frequency arrays** and a **fixed-size sliding window**.

```cpp
int freqs1[26] = {};
int freqs2[26] = {};
```

Each array index represents a lowercase English letter:

- `freqs1[0]` stores the frequency of `'a'` in `s1`.
- `freqs1[1]` stores the frequency of `'b'` in `s1`.
- The same mapping is used for `freqs2`, which tracks the current window in `s2`.

The expression `c - 'a'` converts a lowercase letter into an index from `0` to `25`.

### Steps

1. If `s1` is longer than `s2`, return `false` immediately. A substring of `s2` cannot be long enough to contain a permutation of `s1`.
2. Count the frequency of every character in `s1` and store it in `freqs1`.
3. Expand the window through `s2` using the `right` pointer, adding each character to `freqs2`.
4. When the window length equals `s1.size()`, compare the two frequency arrays.
5. If the arrays match, return `true`: the current window is a permutation of `s1`.
6. Otherwise, remove the leftmost character from `freqs2` and move `left` forward by one, keeping the window size fixed.
7. If no window matches, return `false`.

## Implementation

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int freqs1[26] = {}, freqs2[26] = {}, left = 0;

        for (char c : s1) {
            freqs1[c - 'a']++;
        }

        for (int right = 0; right < s2.size(); right++) {
            freqs2[s2[right] - 'a']++;

            if (right - left + 1 == s1.size()) {
                if (equal(freqs1, freqs1 + 26, freqs2))
                    return true;

                freqs2[s2[left] - 'a']--;
                left++;
            }
        }

        return false;
    }
};
```

The `equal()` function compares all 26 entries in the two arrays. Include `<algorithm>` and `<string>` (or use the usual LeetCode environment, which generally provides the required headers).

## Why It Works

A permutation must contain exactly the same number of each character as `s1`. Comparing the two frequency arrays checks this without needing to compare the character order.

The window always has exactly `s1.size()` characters when the arrays are compared. After checking a window, the algorithm removes its leftmost character and advances `left`, so the next iteration considers the next window of the same length.

Every possible substring of `s2` with length `s1.size()` is checked in this way. If any window has the same frequency counts as `s1`, it is a permutation and the function returns `true`. Otherwise, the function returns `false` after checking all windows.

## Complexity

Let `n = s1.size()` and `m = s2.size()`.

- **Time:** `O(n + m)`. Building `freqs1` takes `O(n)`. Each character in `s2` enters and leaves the window at most once. Comparing the arrays costs `O(26)`, which is `O(1)` because the alphabet size is fixed.
- **Auxiliary space:** `O(1)`, because the two arrays always contain 26 integers.

## Key Learning

> **Use a fixed-size sliding window and frequency arrays when checking whether a substring is an anagram or permutation of a target string.**

The general pattern is:

**Count the target → build a window of the target's length → compare frequencies → slide one position → repeat.**

Unlike problems such as *Longest Repeating Character Replacement*, this problem requires matching the **entire frequency distribution**, not just tracking the highest character frequency.
