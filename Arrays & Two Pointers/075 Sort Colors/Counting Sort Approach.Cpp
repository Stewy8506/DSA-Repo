class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ZeroCount = 0, OneCount = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]==0){
                ZeroCount++;
            } else if (nums[i]==1) {
                OneCount++;
            }
        }
        for (int j = 0; j < nums.size(); j++){
            if (ZeroCount!=0) {
                nums[j]=0;
                ZeroCount--;
            } else if (ZeroCount == 0 && OneCount != 0) {
                nums[j]=1;
                OneCount--;
            } else {
                nums[j]=2;
            }
        }
        return;
    }
};