/*
    Title:          35.SearchInsertPosition.cpp
    Update date:    2020/3/14
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        // (98.02%, 100.00%)
        int left = 0, right = nums.size() - 1;
        int mid;
        
        while(left < right)
        {
            mid = left + (right - left + 1) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        if(left == right)
            return nums[left] < target ? left + 1: left;
        else
            return left;
        
    }
};