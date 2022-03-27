/*
    Title:          300.LongestIncreasingSubsequence.cpp
    Update date:    2022/03/26
    Author:         Zhuofan Zhang
*/

// Method 1
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            int now_max = 1;
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i] && now_max < dp[j]+1)
                {
                    now_max = dp[j] + 1;
                }
            }
            dp[i] = now_max;
            if(res < dp[i])
                res = dp[i];
        }

        return res;
    }
};