/*
    Title:          32.LongestValidParentheses.cpp
    Update date:    2021/10/02
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
            // switch(s[i])
            // {
            //     case '(': 
            //         stk.push(i);break;
            //     case ')':
            //         stk.pop();
            //         if(stk.empty())
            //             stk.push(i);
            //         else
            //         {
            //             int top = stk.top();
            //             int tmpResult = i - top;
            //             if(tmpResult > result)
            //                 result = tmpResult;
            //         }
            // }
                if(s[i] == '(') 
                    stk.push(i);
                else
                {
                    stk.pop();
                    if(stk.empty())
                        stk.push(i);
                    else
                    {
                        int top = stk.top();
                        int tmpResult = i - top;
                        if(tmpResult > result)
                            result = tmpResult;
                    }
                }
                    
        }
        
        return result;
    }
};