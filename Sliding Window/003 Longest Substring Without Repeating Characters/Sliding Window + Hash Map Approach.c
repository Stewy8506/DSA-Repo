class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int max = 0, left = 0, right = 0;
        while (right < s.size()) {
            if (mp.contains(s[right])) {
                left = std::max(left, mp[s[right]] + 1);
            }
            mp[s[right]] = right;
            max = std::max(max, right - left + 1);
            right++;
        }
        return max;
    }
};