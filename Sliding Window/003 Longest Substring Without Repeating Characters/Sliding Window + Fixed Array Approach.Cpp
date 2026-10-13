
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