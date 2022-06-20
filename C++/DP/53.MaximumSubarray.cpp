/*
    Title:          53.MaximumSubarray.cpp
    Update date:    2020/03/20
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        size_t len = nums.size();
        int* dp = new int[len];
        dp[0] = nums[0];
        int result = dp[0];
        
        for(size_t i = 1; i < len; ++i)
        {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            result = result < dp[i] ? dp[i] : result;
        }
        
        return result;
        
    }
};