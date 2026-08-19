class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallPrev = prices[0] , maxDiff = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i]<smallPrev){
                smallPrev = prices[i];
            }
            if ((prices[i]-smallPrev)>maxDiff){
                maxDiff = prices[i] - smallPrev;
            }
        }
        return maxDiff;
    }
};