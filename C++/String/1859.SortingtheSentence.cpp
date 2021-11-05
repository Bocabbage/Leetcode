/*
    Title:          1859. SortingtheSentence.cpp
    Update date:    2021/10/14
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    string sortSentence(string s) {
        
        string result;
        int max_sub = 0;
        for(auto &c : s)
            if(c == ' ')
                max_sub++;
        vector<string> buff(++max_sub);
        
        auto p = 0;
        int idx = 0;
        for(int q = 1; q < s.size(); ++q)
        {
            if(48 <= s[q] && s[q] <= 57)
            {
                idx = s[q] - 49;
                buff[idx] = s.substr(p, q-p);
                p = q + 2;
            }
        }
        
        
        result += buff[0];
        for(size_t i = 1; i < max_sub; ++i)
        {
            if(buff[i].size() == 0)
                break;
            result += ' ';
            result += buff[i];
        }
        return result;
    }
};