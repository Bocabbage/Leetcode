/*
    Title:          34.FindFirstandLastPositionofElementinSortedArray.cpp
    Update date:    2022/05/30
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res{-1, -1};
        if(nums.empty())
            return res;

        int begin = 0, end = nums.size() - 1;
        // find left-bound
        while(begin <= end)
        {
            int mid = (begin + end) >> 1;
            if(nums[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }

        if(begin >= nums.size() || nums[begin] != target)
            return res;
        else
            res[0] = begin;

        // find right-bound
        begin = 0, end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) >> 1;
            if(nums[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
                
        }

        res[1] = end;
        return res;

    }
};