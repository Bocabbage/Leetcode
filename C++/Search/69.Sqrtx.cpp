/*
    Title:          69.Sqrtx.cpp
    Update date:    2022/01/05
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int mySqrt(int x) {
        long long lo = 1, hi = x;
        long long mid = 0;
        double res = 0;
        while(hi-lo>1)
        {
            mid = (lo+hi) >> 1;
            res = double(mid)*mid;
            if(res == x)
                return mid;
            else if(res < x)
                lo = mid;
            else
                hi = mid - 1;
        }

        return (hi*hi > x)? lo : hi;

    }
};