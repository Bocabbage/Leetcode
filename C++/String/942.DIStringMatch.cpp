/*
    Title:          942.DIStringMatch.cpp
    Update date:    2021/11/18
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> res(n + 1, 0);
        int now_min = 0, now_max = n;
        for(size_t i = 0; i < n; ++i)
        {
            if(s[i] == 'I')
                res[i] = now_min++;
            else
                res[i] = now_max--;
        }
        res[n] = now_max;
        return res;
    }
};