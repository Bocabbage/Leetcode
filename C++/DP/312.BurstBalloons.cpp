/*
    Title:          312.BurstBalloons.cpp
    Update date:    2022/08/16
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int solve(int left, int right)
    {
        if(left >= right - 1)
            return 0;
        if(memo[left][right] != -1)
            return memo[left][right];
        
        for(int i = left + 1; i < right; ++i)
        {
            memo[left][right] = max(
                memo[left][right],
                exNums[left] * exNums[i] * exNums[right] + solve(left, i) + solve(i, right)
            );
        }

        return memo[left][right];
    }

    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        exNums.resize(n+2);
        exNums[0] = exNums[n+1] = 1;
        for(int i = 1; i <= n; ++i)
            exNums[i] = nums[i-1];
        
        memo.resize(n+2, vector<int>(n+2, -1));
        return solve(0, n+1);
    }
private:
    vector<int> exNums;
    vector<vector<int>> memo;
};
