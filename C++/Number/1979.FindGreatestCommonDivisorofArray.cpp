/*
    Title:          1979.FindGreatestCommonDivisorofArray.cpp
    Update date:    2021/11/05
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = 0, min = INT_MAX;
        for(auto &n: nums)
        {
            if(n > max)
                max = n;
            if(n < min)
                min = n;
        }
        
        // int end = min >> 1;
        // int res = 1;
        // for(int i = 2; i <= end; ++i)
        // {
        //     if(!(min % i) && !(max % i))
        //         res = i;
        // }
        while(max != min)
        {
            if(max > min)
                max -= min;
            else
                min -= max;
        }
        
        
        return min;
    }
};