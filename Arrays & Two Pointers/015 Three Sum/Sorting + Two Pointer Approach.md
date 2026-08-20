# 3Sum — Sorting + Two Pointers

## Approach

1. Sort the array.
2. Fix `nums[i]` as the first element of the triplet.
3. Use two pointers:
   - `left = i + 1`
   - `right = nums.size() - 1`
4. Compare `nums[left] + nums[right]` with `-nums[i]`.
5. Move:
   - `left++` if the sum is too small.
   - `right--` if the sum is too large.
   - Both pointers if a valid triplet is found.
6. Skip duplicate values to avoid duplicate triplets.

## Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
```

## Complexity

- **Time:** `O(n²)`
  - Sorting: `O(n log n)`
  - Outer loop + two-pointer search: `O(n²)`
  - Overall: `O(n²)`
- **Space:** `O(1)` auxiliary space, excluding the output.

## Key Insight

After sorting, for a fixed `i`:

- If `nums[i] + nums[left] + nums[right] < 0`, increase `left`.
- If the sum is greater than `0`, decrease `right`.
- If the sum is `0`, record the triplet and move both pointers.

Sorting also places duplicate values next to each other, allowing duplicates to be skipped directly without using a `set` or frequency map.

## Why Not O(n)?

The output itself can contain `O(n²)` triplets in the general case, so an `O(n)` solution cannot exist for the standard output-producing version of 3Sum.
