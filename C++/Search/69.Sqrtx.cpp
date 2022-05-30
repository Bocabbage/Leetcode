/*
    Title:          69.Sqrtx.cpp
    Update date:    2022/05/30
    Author:         Zhuofan Zhang
*/

/* Method1: Binary-Search */
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

/* Method2: Newton-Method */
class Solution {
public:
    int mySqrt(int x) 
    {
        double xN = x;
        double xN1 = x - 0.1;

        while(xN - xN1 > 1e-4)
        {
            xN = xN1;
            xN1 = xN - (pow(xN1, 2) - x) / (2*xN);
        }

        return xN1;
    }
};