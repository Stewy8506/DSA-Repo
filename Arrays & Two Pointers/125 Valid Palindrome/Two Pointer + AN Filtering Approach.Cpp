class Solution {
public:
    bool isPalindrome(string s) {
        int leftPoint = 0, rightPoint = s.size() - 1;
        while (leftPoint < rightPoint) {
            while (!isalnum(s[leftPoint]) && leftPoint<rightPoint ) {
                leftPoint++;
            }
            while (!isalnum(s[rightPoint]) && leftPoint<rightPoint ) {
                rightPoint--;
            }
            if (tolower(s[leftPoint])!=tolower(s[rightPoint])){
                return false;
            } else {
                leftPoint++,rightPoint--;
            }
        }
        return true;
    }
};