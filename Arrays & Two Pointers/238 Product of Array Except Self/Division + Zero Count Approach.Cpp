class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int zeroCount = 0, zeroIndex;
        long long prod = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]==0) {
                zeroCount++;
                zeroIndex=i;
                continue;
            } else {
                prod=prod*nums[i];
            }
        }
        for (int j = 0; j< nums.size(); j++){
            if (zeroCount==1 && zeroIndex == j){
                answer[j]=prod;
            } else if (zeroCount==1 && zeroIndex != j){
                answer[j]=0;
            } else if (zeroCount==0){
                answer[j]=prod/nums[j];
            } else {
                answer[j]=0;
            }
        }
        return answer;
    }
};