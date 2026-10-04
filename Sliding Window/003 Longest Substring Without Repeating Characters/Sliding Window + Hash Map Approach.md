# Longest Substring Without Repeating Characters — Sliding Window + Hash Map

## Approach

Use a **sliding window** defined by two pointers, `left` and `right`.

The window represents the current substring being considered. The goal is to keep this window free of duplicate characters while expanding it from left to right.

An `unordered_map<char, int>` stores the **most recent index** at which each character appeared.

For each character at `right`:

1. Check whether the character has appeared before.
2. If it has, move `left` to one position after its previous occurrence.
3. Use `max(left, previousIndex + 1)` so that `left` never moves backwards.
4. Update the character's stored index to the current `right`.
5. Calculate the current window length and update the maximum.
6. Move `right` forward.

For example, with:

```text
"abcabcbb"
```

The window can grow as:

```text
[abc]
```

When the next `a` is encountered, the previous `a` was at index `0`, so `left` moves to `1`:

```text
a[bca]
  ↑ ↑
 left right
```

The window is valid again, and the process continues.

The important observation is that storing the **latest index** lets `left` jump directly past a duplicate instead of removing characters one by one.

## Why It Works

The sliding window maintains the invariant that the substring from `left` through `right` contains no repeated characters.

When a duplicate is found, its previous index tells us where the conflict occurred. Moving `left` to `previousIndex + 1` removes that previous occurrence from the window.

However, the previous occurrence may already be outside the current window. Therefore, `left` must only move forward:

```text
left = max(left, previousIndex + 1)
```

After this adjustment, the window is valid again.

Because every character's latest position is stored in the hash map, duplicate detection and locating the previous occurrence take average `O(1)` time. Each character is processed once by `right`, while `left` only moves forward.

## Complexity

- **Time:** `O(n)` average
- **Auxiliary Space:** `O(min(n, k))`, where `k` is the number of possible distinct characters
- **Output Space:** `O(1)`

For a fixed character set such as ASCII, the auxiliary space is effectively `O(1)`.

## Why Use This Approach?

This approach avoids repeatedly checking overlapping substrings.

The hash map provides fast access to the previous position of each character, allowing the left pointer to **jump directly** instead of moving one character at a time.

Compared with brute force, this reduces the average time complexity to `O(n)` at the cost of additional memory for the hash map.

## Key Learning

> **Use a sliding window with a hash map when a contiguous range must maintain a property while moving through a sequence.**

A useful general pattern is:

**Right expands → detect violation → left jumps forward → restore validity → continue.**

The `max(left, previousIndex + 1)` pattern is important whenever a sliding-window boundary must never move backwards.
