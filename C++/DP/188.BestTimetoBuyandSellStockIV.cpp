/*
    Title:          188.BestTimetoBuyandSellStockIV.cpp
    Update date:    2022/06/08
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    int Dp(
        int x, int y, int z, 
        vector<vector<vector<int>>>& dp, const vector<int>& prices
    )
    {
        if(x == -1)
        {
            if(z == 0)
                return 0;
            else 
                return INT_MIN;
        }

        if(dp[x][y][z] != INT_MAX)
            return dp[x][y][z];
        
        // now don't have stock
        dp[x][y][0] = max(Dp(x-1, y, 0, dp, prices), Dp(x-1, y, 1, dp, prices)+prices[x]);
        // now have stock
        dp[x][y][1] = max(Dp(x-1, y, 1, dp, prices), Dp(x-1, y-1, 0, dp, prices)-prices[x]);

        return dp[x][y][z];
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        vector<vector<vector<int>>> dp(
            prices.size(), vector<vector<int>>(k+1, vector<int>(2, INT_MAX))
        );

        for(int i = 0; i < prices.size(); ++i)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }

        return Dp(prices.size()-1, k, 0, dp, prices);
    }
};