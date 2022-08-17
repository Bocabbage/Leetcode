/*
    Title:          406.QueueReconstructionbyHeight.cpp
    Update date:    2022/08/17
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        vector<vector<int>> res(people.size(), vector<int>{-1, -1});
        sort(
            people.begin(),
            people.end(),
            [](const vector<int>& v1, const vector<int>& v2)
            {
                return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);
            }
        );

        for(auto &p: people)
        {
            int cnt = 0;
            for(int i = 0; i < res.size(); ++i)
            {
                if(res[i][0] != -1)
                    continue;
                
                if(cnt == p[1])
                {
                    res[i] = p;
                    break;
                }
                else
                    cnt++;
            }
        }

        return res;
    }
};