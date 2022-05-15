/*
    Title:          31.NextPermutation.cpp
    Update date:    2022/05/15
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0)
        {
            if(nums[i] > nums[i-1])
                break;
            i--;
        }
        
        if(i)
        {
            for(int j = nums.size() - 1; j >= i; --j)
            {
                if(nums[i-1] < nums[j])
                {
                    swap(nums[i-1], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i, nums.end());
    }
};