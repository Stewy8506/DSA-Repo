class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sample=nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == sample){
                return true;
            } else {
                sample=nums[i];
            }
        }
        return false;   
    }
};