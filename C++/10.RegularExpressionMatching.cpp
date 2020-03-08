/*
    Title:          10.RegularExpressionMatching.cpp
    Update date:    2020/3/8
    Author:         Zhuofan Zhang
    Method:         Dynamic Programming(93.14%, 90%)
*/

class Solution{
private:
    uint8_t **memo;
public:
    bool isMatch(string s, string p) 
    {
        /*
            0: No cache
            1: Match
            2: Mismatch
        */
        memo = new uint8_t* [s.length()+1];
        for(size_t i=0;i<=s.length();++i)
            memo[i] = new uint8_t[p.length()+1]();
        
        return dp(0,0,s,p);
    }
    
    bool dp(int ps, int pp, string &text, string &pattern)
    {
        // If has been visited, return the answer directly
        if(memo[ps][pp] != 0)
            return memo[ps][pp] == 1;
        
        bool ans;
        if(pp == pattern.length())
            ans = (ps == text.length());
        else
        {
            // The now-processing char is matched or not
            bool first_match = ( 
                                 ps < text.length() && 
                                (pattern[pp] == text[ps] ||
                                 pattern[pp] == '.')
                               );
            
            // If the next pattern char is '*'
            if(pp+1 < pattern.length() && pattern[pp+1] == '*')
                ans = (dp(ps,pp+2, text, pattern) || 
                       (first_match && dp(ps+1, pp, text, pattern)));
            else
                ans = (first_match && dp(ps+1, pp+1, text, pattern));
        }
        
        memo[ps][pp] = ans? 1: 2;
        return ans;
    }
};

// class Solution {
// public:
//     bool isMatch(string s, string p) 
//     {
//         if( p == ".*" )
//             return true;
        
//         /* Method1: FSM */
//         size_t ps = 0, pp = 0;
//         size_t last_start = ps;
//         auto plen = p.length(),slen = s.length();
        
//         size_t state = 0;
        
//         // case like "aaa" & "ab*a*c*a"
//         char last_star;
//         bool last_star_use = false;
        
//         while(ps < slen)
//         {
//             switch(state)
//             {
//                 case 0:
//                     if(p[0] == '*')return false;

//                     if(p[0] == '.' || p[0] == s[0])
//                     {
//                         pp++;ps++;
//                         state = 1;
//                     }
//                     else if(p[1] == '*')
//                     {
//                         pp++;
//                         state = 2;       
//                     }
//                     else
//                         return false;
//                     break;
                    
//                 case 1:
//                     while(pp<plen && ps<slen && p[pp] == s[ps])
//                     {pp++;ps++;}
//                     if(pp == plen && ps == slen)
//                         return true;
//                     else if(pp == plen)
//                         return false;
//                     else if(ps == slen)
//                     {
//                         if(pp == (plen-2) && p[plen-1] == '*')
//                             return true;
//                         else
//                             return false;
//                     }
//                     else if(p[pp] == '.')
//                     { pp++;ps++; }
//                     else if(p[pp] == '*')
//                         state = 2;
//                     else if(p[pp+1] == '*')
//                         pp += 2;
//                     else
//                         return false;
//                     break;
                    
//                 case 2:
//                     char former = p[pp-1];
//                     if(former == '.')
//                     {
//                         pp++;
//                         if(pp == plen)
//                             return true;
//                         else
//                             return isMatch(s.substr(ps-1),p.substr(pp));
//                     }
                    
//                     // case like "aaa" & "a*a"
//                     auto s_p = pp+1;
//                     auto s_s = ps;
//                     if(p[s_p] == former)
//                     {
//                         while(s_p < plen && s_s < slen && 
//                               p[s_p] == former && s[s_s] == former)
//                             s_s++,s_p++;
//                         if(s_p < plen && p[s_p] == former)
//                             return false;
//                         else if(s_p == plen)
//                             return true;
//                         pp = s_p;
//                         ps = s_s;
//                         state = 1;
//                         break;
//                     }

//                     while(ps < slen && s[ps] == former)ps++;
//                     pp++;
//                     state = 1;
//                     break;
//             }
            
//         }
        
//         if(pp < plen)
//             return false;
//         else
//             return true;
//     }
// };