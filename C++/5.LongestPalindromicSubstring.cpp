/*
    Title:          5.LongestPalindromicSubstring.cpp
    Update date:    2019/09/14
    Author:         Zhuofan Zhang
*/

/* 
    Method1:
    Space   : O(n) [need sub-string copy]
    Time    : O(n^3) [worst case]

 */
// class Solution 
// {
// public:
//     string longestPalindrome(string s)
//     {
//         if(s.length()==0 || s.length()==1)
//             return s;
//         size_t p=0,q,max_len=0;
//         size_t res_p=0,res_q=0;
//         for(;p<s.length();++p)
//         {
//             if(s.length()-p < max_len)
//                 break;
//             for(q=s.length()-1;q>p;--q)
//             {
//                 if(s[p]==s[q])
//                 {    
//                     string sub = s.substr(p,q-p+1);
//                     // string sub = rsub;
//                     // reverse(rsub.begin(),rsub.end());
//                     if(sub.length() <= max_len)
//                         break;
                    
//                     bool IsPalin = true;
//                     size_t sp=0,sq=sub.length()-1;
//                     while(sp<sq)
//                     {
//                         if(sub[sp++]!=sub[sq--])
//                         {
//                             IsPalin = false;
//                             break;
//                         }
//                     }
                    
//                     if(IsPalin)
//                     {
//                         max_len = sub.length();
//                         res_p = p,res_q = q;
//                         break;
//                     }
//                 }
//             }
//         }
//         return s.substr(res_p,res_q-res_p+1);
//     }
// };


/* 
    Method2:
    Space   : O(1) [in-place]
    Time    : O(n^2) [worst case]

 */
class Solution 
{
public:
    string longestPalindrome(string s)
    {
        if(s.length()==0 || s.length()==1)return s;
        size_t MaxLen = 0,p=0;
        
        for(int i=0;i<s.length();++i)
        {
            if(MaxLen > 2*(s.length()-1-i))
                break;
            int lp = i-1;
            while((i+1)<s.length() && s[i+1]==s[i])
                i++;
            int rp = i+1;
            while(lp>=0 && rp<=s.length())
            {
                if(s[lp]!=s[rp])
                    break;
                lp--,rp++;
            }   
            if(rp-lp-1 > MaxLen)
            {
                MaxLen = rp-lp-1;
                p = lp+1;
            }
                
            
        }
        
        return s.substr(p,MaxLen);
    }
};