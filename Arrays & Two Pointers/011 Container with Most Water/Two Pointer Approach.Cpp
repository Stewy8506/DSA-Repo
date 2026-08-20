class OptimisedSolution {
public:
    int getArea(int leftIndex, int rightIndex, vector<int>& height) {
        return min(height[leftIndex], height[rightIndex]) *
               (rightIndex - leftIndex);
    }
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        
        while (left < right){
            maxArea = max(maxArea, getArea(left, right, height));
            if (height[left]<height[right]) {
                left++; 
            } else {
                right--;
            }
        }
        return maxArea;
    }
};



class Solution {
public:
    int getArea(int leftIndex, int rightIndex, vector<int>& height) {
        return min(height[leftIndex], height[rightIndex]) *
               (rightIndex - leftIndex);
    }
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1,
            maxArea = getArea(left, right, height);
        
        while (left < right){
            if (height[left]<height[right]) {
                if (maxArea < getArea(left,right,height)){
                    maxArea = getArea(left,right,height);
                }
                left++;
            } else {
                if (maxArea < getArea(left,right,height)){
                    maxArea = getArea(left,right,height);
                }
                right--;
            }
        }
        return maxArea;
    }
};