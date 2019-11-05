/*
    Title:          9.PalindromeNumber.cpp
    Update date:    2019/11/05
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    bool isPalindrome(int x) 
    {
        /* Method1:(72.67%,99.09%) */
        if(x < 0)return false;
        string num = to_string(x);
        auto p = num.cbegin(), q = num.cend() - 1;
        while(p<q)
        {
            if(*p!=*q)
                return false;
            p++;q--;
        }
        
        return true;
        
        /* 
            Method2:(51.01%,100%) 
            Note that use 'x!=0' will faster than 'x>0'.
        */
        // if(x < 0)return false;
        // long rev = 0,num = x;
        // while(x != 0)
        // {
        //     rev = 10*rev + x%10;
        //     x /= 10;
        // }
        
        // return rev == num;
    }
};