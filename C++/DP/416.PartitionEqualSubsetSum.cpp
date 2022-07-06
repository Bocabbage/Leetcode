/*
    Title:          416.PartitionEqualSubsetSum.cpp
    Update date:    2022/07/06
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    bool dpSearch(
        vector<vector<int>>& dp,
        const vector<int>& nums,
        int n, int price
    )
    {
        if(n < 0)
            return price == 0;

        if(price < 0)
            return false;

        if(dp[n][price] != 0)
            return dp[n][price] == 1;
        
        if(dpSearch(dp, nums, n-1, price) || dpSearch(dp, nums, n-1, price - nums[n]))
            dp[n][price] = 1;
        else
            dp[n][price] = -1;
        
        return dp[n][price] == 1;
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 0x1)
            return false;
        
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2+1, 0));
        return dpSearch(dp, nums, nums.size() - 1, sum/2);
    }

};