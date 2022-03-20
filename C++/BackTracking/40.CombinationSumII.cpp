/*
    Title:          40.CombinationSumII.cpp
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
        if(target == 0)
        {
            res.emplace_back(combine);
            return;
        }

        if(idx >= candidates.size())
            return;

        // find the next candidate that not equal to candidates[idx]
        int next_idx = idx + 1;
        while(next_idx < candidates.size() && candidates[next_idx] == candidates[idx])
            next_idx++;
        if(next_idx < candidates.size() && candidates[next_idx] <= target)
            dfs(candidates, target, next_idx, combine, res);

        if(candidates[idx] <= target)
        {
            combine.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], idx+1, combine, res);
            combine.pop_back();
        }
        

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> combine;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, combine, res);
        return res;
    }
};