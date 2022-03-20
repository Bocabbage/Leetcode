/*
    Title:          48.RotateImage.cpp
    Update date:    2022/03/20
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    void rotateCore(
        vector<vector<int>>& matrix,
        int k
    )
    {
        int n = matrix.size();
        if(k >= (n>>1))
            return;
        

        int tmp;
        for(int i = k; i < n - k - 1; ++i)
        {
            tmp = matrix[k][i];
            swap(matrix[n - i - 1][k], matrix[k][i]);                   // left-down to left-up
            swap(matrix[n - k - 1][n - i - 1], matrix[n - i - 1][k]);   // right-down to left-down
            swap(matrix[i][n - k - 1], matrix[n - k - 1][n - i - 1]);   // right-up to right-down
            matrix[i][n - k - 1] = tmp;                                 // left-up to right-up
        }

        rotateCore(matrix, k+1);
    }

    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        rotateCore(matrix, 0);
    }
};