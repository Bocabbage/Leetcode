/*
    Title:          12.IntegertoRoman.cpp
    Update date:    2019/11/04
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    string intToRoman(int num)
    {
        /* 
            Method1(inner-loop):(50.79%,100.00%)
            Method2(discard division):(94.51%,97.37%)
        */
        int bases[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        char* sig[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        const size_t base_nums = 13;
        
        string res;
        size_t now_idx = 0;
        
        while( now_idx < base_nums )
        {
            if(num < bases[now_idx])
            {
                now_idx++;
                continue;
            }
            
            // int base_weight = num / bases[now_idx];
            // num -= base_weight * bases[now_idx];

            // while(base_weight > 0)
            // {
            //     res += sig[now_idx];
            //     base_weight--;
            // }
            
            // now_idx++;
            
            num -= bases[now_idx];
            res += sig[now_idx];
        }
        
        return res;
    }
};