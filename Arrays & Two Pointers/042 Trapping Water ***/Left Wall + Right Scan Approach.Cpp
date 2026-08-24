class Solution {
public:
    int calcWell(vector<int>& height, int left, int right) {
        int waterLevel = min(height[left], height[right]);
        int water = 0;

        for (int i = left + 1; i < right; i++) {
            water += waterLevel - height[i];
        }

        return water;
    }

    int trap(vector<int>& height) {
        int n = height.size();

        if (n < 3)
            return 0;

        int left = 0;
        int total = 0;

        while (left < n - 2) {
            int tallestIndex = -1;

            for (int i = left + 1; i < n; i++) {
                if (height[i] >= height[left]) {
                    tallestIndex = i;
                    break;
                }
                if (tallestIndex == -1 ||
                    height[i] > height[tallestIndex]) {
                    tallestIndex = i;
                }
            }
            if (tallestIndex != -1) {
                total += calcWell(height, left, tallestIndex);
                left = tallestIndex;
            }
        }

        return total;
    }
};