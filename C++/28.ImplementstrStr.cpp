/*
    Title:          28.ImplementstrStr.cpp
    Update date:    2020/3/12
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        // For the clarification of the Question
        // when meet empty needle
        if(needle.size() == 0)
            return 0;
        
        // if(needle.size() < 100)
        //     return Naive(haystack, needle);
        
        // KMP
        return KMP(haystack, needle);
        
        
    }
    
    
    inline vector<int> ComputePrefixFunction(string& needle)
    {
        int n_size = needle.size();
        vector<int> result(n_size);
        result[0] = -1;
        int k = -1;
        for(int i = 1; i < n_size; ++i)
        {
            while(k >= 0 && needle[k+1] != needle[i])
                k = result[k];
            if(needle[k+1] == needle[i])
                k++;
            result[i] = k;
        }
        
        return result;
    }
    
    inline int KMP(string &haystack, string &needle)
    {
        // (90.12%, 100.00%)
        vector<int> prefix_arr = ComputePrefixFunction(needle);
        int h_size = haystack.size(), n_size = needle.size();
        
        int i=0, j=-1;
        while(i < h_size)
        {
            while(j >= 0 && haystack[i] != needle[j+1])
                j = prefix_arr[j];
            if(haystack[i] == needle[j+1])
                j++;
            if(j == n_size - 1)
                return i - n_size + 1;
            i++;
        }
        
        return -1;
    }
    
    inline int Naive(string &haystack, string &needle)
    {
        // (16.21%, 100.00%)
        size_t hp = 0;
        size_t h_size = haystack.size(), n_size = needle.size();
         
        while(hp < h_size)
        {
            if(haystack[hp] == needle[0])
            {
                size_t i = 1;
                for(; i < n_size; ++i)
                    if(haystack[hp + i] != needle[i])
                        break;
                if(i == n_size)
                    return hp;
            }
            hp++;
        }
        
        return -1;
    }
};