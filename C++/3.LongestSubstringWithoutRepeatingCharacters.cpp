/*
    Title:          3.LongestSubstringWithoutRepeatingCharacters.cpp
    Update date:    2021/09/19
    Author:         Zhuofan Zhang
    Latest Method:  Use Bool-Bucket
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alphaLocation[128];
        for(size_t i = 0; i < 128; ++i)
            alphaLocation[i] = -1;
        int result = 0;
        int nowLen = 0;
        int p = 0;
        int q = 0;
        int idx;
        
        while(q < s.size())
        {
            idx = (int)(s[q]);
            if (alphaLocation[idx] == -1 || alphaLocation[idx] < p)
                alphaLocation[idx] = q;
            else
            {
                if(nowLen > result)
                    result = nowLen;
                p = alphaLocation[idx] + 1;
                alphaLocation[idx] = q;
                nowLen = q - p;
            }
            q++;
            nowLen++;
        }
        
        if(nowLen > result)
            result = nowLen;

        return result;
    }
};