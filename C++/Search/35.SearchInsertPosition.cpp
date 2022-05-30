/*
    Title:          35.SearchInsertPosition.cpp
    Update date:    2022/05/30
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int begin = 0, end = nums.size() - 1;

        while(begin <= end)
        {
            int mid = (begin + end) >> 1;
            if(nums[mid] < target)
                begin = mid + 1;
            else if(nums[mid] >= target)
                end = mid - 1;
        }

        return begin;

    }
};