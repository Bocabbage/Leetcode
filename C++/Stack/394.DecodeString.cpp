/*
    Title:          394.DecodeString.cpp
    Update date:    2022/06/27
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    string decodeString(string s) 
    {
        stack<string> stk;
        stack<int> numStk;
        string result;

        int n = s.length();
        int i = 0;
        while(i < n)
        {
            if(s[i] == '[' || (s[i] >= 'a' && s[i] <= 'z'))
            {
                stk.push(string{s[i]});
                i++;
            }
            else if(s[i] == ']')
            {
                int k = numStk.top();
                numStk.pop();

                string sub;
                while(!stk.empty() && stk.top() != "[")
                {
                    sub += stk.top();
                    stk.pop();
                }
                stk.pop(); // pop-out the '['

                string subRes;
                for(int t = 0; t < k; ++t)
                    subRes += sub;

                
                stk.push(std::move(subRes));
                i++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                int j = i;
                while(j < n && s[j] >= '0' && s[j] <= '9')
                    j++;
                string strK = s.substr(i, j-i);
                numStk.push(stoi(strK));
                i = j;
            }
                
        }


        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};