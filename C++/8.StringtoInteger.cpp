/*
    Title:          8.StringtoInteger.cpp
    Update date:    2019/10/01
    Author:         Zhuofan Zhang
*/

// Method1: Use 'istringstream' module
// Method2: Direct string read

class Solution {
public:
    int myAtoi(string str) 
    {
        
        // istringstream get_digit(str);
        // string may_digit;
        // get_digit >> may_digit;
        
        
        // if(may_digit[0] != '-' && may_digit[0] != '+' && (may_digit[0] >'9' || may_digit[0]<'0'))
        //    return 0;
        auto first = str.cbegin();
        while(first != str.cend())
        {
            if(*first == ' ')
                ++first;
            else if(*first == '+' || *first == '-' || (*first <= '9' && *first >= '0'))
                break;
            else
                return 0;
        }
        
        str = string(first,str.cend());
        bool IsMinus = false;
        if(str[0] == '-' || str[0] == '+')
        {
            if(str[1] > '9' || str[1] < '0')
                return 0;
            IsMinus = (str[0]=='-')?true:false;
            str = str.substr(1);
        }
        double res = 0;
        for(auto digit = str.cbegin();
            digit != str.cend();
            ++digit)
        {
            if(*digit > '9' || *digit < '0')
                break;
            res = 10*res + ((*digit)-48);
        }
        // bool IsMinus = false;
        // if(may_digit[0] == '-' || may_digit[0] == '+')
        // {
        //     if(may_digit[1] > '9' || may_digit[1] < '0')
        //         return 0;
        //     IsMinus = (may_digit[0]=='-')?true:false;
        //     may_digit = may_digit.substr(1);
        // }
        // double res = 0;
        // for(auto digit = may_digit.cbegin();
        //     digit != may_digit.cend();
        //     ++digit)
        // {
        //     if(*digit > '9' || *digit < '0')
        //         break;
        //     res = 10*res + ((*digit)-48);
        // }
        
        if(IsMinus)
            res = -res;
        
        if(res > INT_MAX)
            return INT_MAX;
        if(res < INT_MIN)
            return INT_MIN;
        
        
        else return res;
    }
};