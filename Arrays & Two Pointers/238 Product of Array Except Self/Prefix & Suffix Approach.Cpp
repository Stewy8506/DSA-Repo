class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(),1);
        int prevProd = 1, nextProd = 1;
        for (int i = 0; i < nums.size(); i++){
            answer[i]*=prevProd;
            prevProd*=nums[i];
        }
        for (int j = (nums.size()-1); j >= 0; j--){
            answer[j]*=nextProd;
            nextProd*=nums[j];
        }
        return answer;
    }
};