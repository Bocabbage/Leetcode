/*
    Title:          35.SearchInsertPosition.cpp
    Update date:    2022/01/05
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int numsSize = nums.size();
        int a = 0, b = numsSize;
        int mid;
        
        if(nums[0] >= target)
            return 0;
        if(nums[b-1] < target)
            return b;
        
        while(b-a>1)
        {
            mid = (a+b)/2;
            if(target > nums[mid])
                a = mid;
            else if(target < nums[mid])
                b = mid;
            else
                return mid;
        }
        
       return b;
        
    }
};