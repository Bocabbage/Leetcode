/*
    Title:          20.ValidParentheses.cpp
    Update date:    2019/11/06
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    bool isValid(string s) 
    {
        /* Method1:(100.00%,96.12%) */
        stack<char> parse_stack;
        for(auto &p: s)
        {
            switch(p)
            {
                case '(':parse_stack.push('(');break;
                case '[':parse_stack.push('[');break;
                case '{':parse_stack.push('{');break;
                case ')':
                    if( parse_stack.empty() || parse_stack.top()!='(' )
                        return false;
                    else
                        parse_stack.pop();
                    break;
                case ']':
                    if( parse_stack.empty() || parse_stack.top()!='[' )
                        return false;
                    else
                        parse_stack.pop();
                    break;
                case '}':
                    if( parse_stack.empty() || parse_stack.top()!='{' )
                        return false;
                    else
                        parse_stack.pop();
                    break;
                default:;
            }
              
        }
        
        return parse_stack.empty();
    }
};