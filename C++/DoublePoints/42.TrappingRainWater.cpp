/*
    Title:          42.TrappingRainWater.cpp
    Update date:    2022/05/12
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int leftIdx = 0, rightIdx = height.size() - 1;
        int result = 0;

        while(leftIdx < rightIdx)
        {
            leftMax = max(leftMax, height[leftIdx]);
            rightMax = max(rightMax, height[rightIdx]);

            if(leftMax < rightMax)
            {
                result += leftMax - height[leftIdx];
                leftIdx++;
            }
            else
            {
                result += rightMax - height[rightIdx];
                rightIdx--;
            }
        }

        return result;
    }
};