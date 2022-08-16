/*
    Title:          6100.CountNumberofWaystoPlaceHouses.cpp
    Update date:    2022/06/26
    Author:         Zhuofan Zhang
*/
class Solution 
{
public:
    int countHousePlacements(int n) 
    {
        vector<vector<long long>> f(n, vector<long long>(2, 0));
        const int MOD = 1000000007;
        f[0][0] = 1, f[0][1] = 1;

        for(int i = 1; i < n; ++i)
        {
            // DP:
            // f(i, 0) = f(i-1, 1) + f(i-1, 0)
            // f(i, 1) = f(i-1, 0)
            f[i][0] = (f[i-1][0] + f[i-1][1]) % MOD;
            f[i][1] = f[i-1][0] % MOD;
        }

        long long res = (f[n-1][0] + f[n-1][1]) % MOD;
        return res*res % MOD;
    }
};