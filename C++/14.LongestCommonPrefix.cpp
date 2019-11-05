/*
    Title:          14.LongestCommonPrefix.cpp
    Update date:    2019/11/05
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        /* Method1:(95.10%,90.32%) */
        const size_t vlen = strs.size();
        if(strs.size() == 0)
            return string("");
        size_t slens[vlen];
        for(size_t i=0; i<vlen;++i)
            slens[i] = strs[i].length();
        
        size_t now_idx = 0;
        while(true)
        {  
            for(size_t i=0; i<vlen; ++i)
            {
                if( now_idx >= slens[i] )
                    return strs[0].substr(0,now_idx);
                char now_chr = strs[0][now_idx];
                if(strs[i][now_idx]!=now_chr)
                    return strs[0].substr(0,now_idx);
            }
            now_idx++;
        }
    }
};