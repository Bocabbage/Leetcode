/*
    Title:          39.CombinationSum.cpp
    Update date:    2022/03/20
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    void dfs(
        vector<int>& candidates,
        int target,
        int idx,
        vector<int>& combine,
        vector<vector<int> >& res
    )
    {
        if(res.size() >= 150 || target < 0 || idx >= candidates.size())
            return;
            
        if(target == 0)
        {
            res.emplace_back(combine);
            return;
        }

        combine.push_back(candidates[idx]);
        dfs(candidates, target-candidates[idx], idx, combine, res);
        combine.pop_back();

        dfs(candidates, target, idx+1, combine, res);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        multiset<int> combine;
        dfs(candidates, target, 0, combine, res);
        return res;
    }
};