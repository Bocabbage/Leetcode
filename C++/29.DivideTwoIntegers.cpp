/*
    Title:          29.DivideTwoIntegers.cpp
    Update date:    2021/09/28
    Author:         Zhuofan Zhang
*/
class Solution {
public:
   long mul(long a, long b){
        long res = 0;
        while (b) {
                if (b & 1)
                     res += a;
                b >>= 1;
                a += a;
        }
        return res;
  }

  int divide(int dividend, int divisor){
        long dd = dividend;
        long dr = divisor;
        bool is_sign = (dividend ^ divisor) >> 31;
        
        if (dd < 0)
                dd = 0 - dd;
        if (dr < 0)
                dr = 0 - dr;
        
        long l = 0;
        long r = dd;
        long tmp, mid;
        /* r is the quotient */
        while (l <= r) {
                mid = l + (r - l) / 2;
                tmp = mul(mid, dr); 
                if (mul(mid, dr) == dd) {
                        r = mid;
                        break;
                } else if (mul(mid, dr) > dd)
                        r = mid - 1;
                else
                        l = mid + 1;
        }
        
        int min = 0x80000000;
        int max =0x7fffffff;
        if (is_sign) {
                r = 0 - r;
                return r > min ? r : min;
        }
        return r < max ? r : max;      
   }
};