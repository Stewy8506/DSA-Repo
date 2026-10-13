class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 1, right = k, maxval = *max_element(nums.begin(), nums.begin()+k), maxidx = max_element(nums.begin(), nums.begin()+k) - nums.begin();
        vector<int> out;
        out.push_back(maxval);
        while (right < nums.size()){
            if (left > maxidx){
                maxidx = max_element(nums.begin() + left, nums.begin() + right + 1) - nums.begin();
                maxval = *max_element(nums.begin() + left, nums.begin() + right + 1);
            }
            if (nums[right] > maxval){
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