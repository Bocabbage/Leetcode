/*
    Title:          1282.GroupthePeopleGiventheGroupSizeTheyBelongTo.cpp
    Update date:    2021/11/05
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        vector<vector<int>> notfull_groups(groupSizes.size(), vector<int>());
        
        for(int i = 0; i < groupSizes.size(); i++)
        {
            int p = groupSizes[i];
            notfull_groups[p-1].push_back(i);
            if(notfull_groups[p-1].size() == p)
            {
                res.push_back(notfull_groups[p-1]);
                notfull_groups[p-1].clear();
            }
                
        }
        
        return res;
    }
};
/*
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        map<int, vector<int>> size2group;
        
        for(int i = 0; i < groupSizes.size(); i++)
        {
            int p = groupSizes[i];
            auto p_group = size2group.find(p);
            if(p_group == size2group.end())
                size2group[p] = vector<int>();
            
            size2group[p].push_back(i);
            if(size2group[p].size() == p)
            {
                res.push_back(size2group[p]);
                size2group.erase(p);
            }
        }
        
        return res;
    }
};
*/