/*
    Title:          35.SearchInsertPosition.cpp
    Update date:    2020/3/14 --> 2021/10/01
    Author:         Zhuofan Zhang
*/

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) 
//     {
//         // (98.02%, 100.00%)
//         int left = 0, right = nums.size() - 1;
//         int mid;
        
//         while(left < right)
//         {
//             mid = left + (right - left + 1) / 2;
//             if(nums[mid] == target)
//                 return mid;
//             else if(nums[mid] < target)
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
        
//         if(left == right)
//             return nums[left] < target ? left + 1: left;
//         else
//             return left;
        
//     }
// };

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