/*
    Title:          6.ZigZagConversion.cpp
    Update date:    2021/08/16
    Author:         Zhuofan Zhang
*/

/* 
    Method:
    Space   : O(n)
    Time    : O(n)
 */
class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return string(s);
        
        string result;
        int sLen = s.length();
        // The first line
        for(int i = 0; i < sLen; i += 2 * (numRows - 1))
            result.push_back(s[i]);
        
        // The middle lines
        for(int i = 1; i < numRows - 1; ++i)
        {
            int j = i;
            bool longstep = true;
            while(j < sLen)
            {
                result.push_back(s[j]);
                if(longstep)
                {
                    j += 2 * (numRows - 1 - i);
                    longstep = false;
                }
                else
                {
                    j += 2 * i;
                    longstep = true;
                }
            }
        }
        
        // The last line
        for(int i = numRows - 1; i < sLen; i += 2*(numRows - 1))
            result.push_back(s[i]);
        
        return result;
    }
};