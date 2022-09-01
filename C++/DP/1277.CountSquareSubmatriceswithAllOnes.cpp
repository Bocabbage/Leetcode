/*
    Title:          1277.CountSquareSubmatriceswithAllOnes.cpp
    Update date:    2022/09/01
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int res = 0;

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(matrix[i][j] == 1)
                {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    
                    res += dp[i][j];
                }
            }
        }

        return res;
    }
};