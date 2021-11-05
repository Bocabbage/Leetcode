
/*
    Title:          763.PartitionLabels.cpp
    Update date:    2021/11/5
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> max_idx;
        for(size_t i = 0; i < s.size(); ++i)
            max_idx[s[i]] = i;

        vector<int> res;
        int start = 0;
        int max_idx_in_part = 0;
        for(size_t i = 0; i < s.size(); ++i)
        {
            max_idx_in_part = max_idx[s[i]] > max_idx_in_part ? max_idx[s[i]] : max_idx_in_part;
            if(i == max_idx_in_part)
            {
                res.push_back(max_idx_in_part - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};