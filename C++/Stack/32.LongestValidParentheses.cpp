/*
    Title:          32.LongestValidParentheses.cpp
    Update date:    2022/05/22
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int sLen = s.length();
        int result = 0;
        
        stk.push(-1);
        for(int i = 0; i < sLen; ++i)
        {
            if(s[i] == '(') 
                stk.push(i);
            else
            {
                stk.pop();
                if(stk.empty()) // No leftParenthese can be matched
                    // As the left-bound 
                    stk.push(i);
                else
                {
                    int top = stk.top(); // top: the leftBound
                    int tmpResult = i - top;
                    if(tmpResult > result)
                        result = tmpResult;
                }
            }
                    
        }
        
        return result;
    }
};