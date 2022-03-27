/*
    Title:          494.TargetSum.cpp
    Update date:    2022/03/27
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int Dp(
        vector<int> &nums,
        vector<vector<int> > &dp,
        int idx,
        int target,
        int acc
    )
    {
        if(target+acc < 0)
            return 0;

        if(dp[idx][target+acc] != -1)
            // have calculated
            return dp[idx][target+acc];

        if(idx == 0)
        {
            if(nums[idx] == target || nums[idx] == -target)
            {
                dp[idx][target+acc] = 1;
                if(target == 0)
                    dp[idx][target+acc]++;
            }
            else
                dp[idx][target+acc] = 0;
            
            return dp[idx][target+acc];
        }        
        int res = 0;
        dp[idx][target+acc] = Dp(nums, dp, idx-1, target+nums[idx], acc) +
                              Dp(nums, dp, idx-1, target-nums[idx], acc);

        return dp[idx][target+acc];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int acc = accumulate(nums.begin(), nums.end(), 0);
        if(nums.empty() || acc < target || -acc > target)
            return 0;
        if(acc == 0 && target == 0)
            return 1 << nums.size();
        
        vector<vector<int> > dp(nums.size(), vector<int>(acc<<1 + 1, -1));
        return Dp(nums, dp, nums.size()-1, target, acc);
    }
};