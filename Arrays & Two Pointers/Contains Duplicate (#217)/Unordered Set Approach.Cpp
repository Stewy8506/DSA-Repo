class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int sample : nums){
            if (seen.find(sample) != seen.end()) {
                return true;
            }
            seen.insert(sample);
        }
        return false;   
    }
};