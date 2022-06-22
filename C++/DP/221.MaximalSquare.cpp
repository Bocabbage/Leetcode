/*
    Title:          221.MaximalSquare.cpp
    Update date:    2022/06/21
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int result = 0;
        int m = dp.size(), n = dp[0].size();
        for(int i = 0; i < m; ++i)
        {
            dp[i][0] = matrix[i][0] - '0';
            result = max(dp[i][0], result);
        }
            
        for(int j = 0; j < n; ++j)
        {
            dp[0][j] = matrix[0][j] - '0';
            result = max(dp[0][j], result);
        }

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    result = max(result, dp[i][j]);
                }
            }
        }

        return result*result;
    }
};