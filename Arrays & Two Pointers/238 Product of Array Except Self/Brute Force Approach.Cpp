//Even though this is a correct brute force approach, it does not meet the time constraints, thus will not pass.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); i++){
            int prod=1;
            for (int k = i + 1; k < nums.size(); k++){
                prod=prod*nums[k];
            }
            for (int j = 0; j < i; j++){
                prod=prod*nums[j];
            }
            answer[i]=prod;
        }
        return answer;
    }
};