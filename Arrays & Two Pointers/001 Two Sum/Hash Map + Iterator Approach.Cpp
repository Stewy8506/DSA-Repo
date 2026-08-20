class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];
            auto it = map.find(needed);
            if (it != map.end()) {
                return {i,it->second};
            } else {
                map[nums[i]]=i;
            }
        }
        return{};
    }
};