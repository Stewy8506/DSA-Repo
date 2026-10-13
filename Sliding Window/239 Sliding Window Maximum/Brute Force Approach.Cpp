class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        int i = 0, currmax;
        while ( i + k <= nums.size()){
            vector<int> window;
            for (int j = i; j < i + k; j++){
                window.push_back(nums[j]);
            }
            currmax = *max_element(window.begin(), window.end());
            out.push_back(currmax);
            i++;
        }
        return out;
    }
};