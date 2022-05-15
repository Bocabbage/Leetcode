/*
    Title:          46.Permutations.cpp
    Update date:    2022/05/15
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    void dfs(
        vector<int>& nums,
        int start,
        vector<int>& nowResult
    )
    {
        if(start == nums.size())
        {
            result.push_back(nowResult);
            return;
        }
        
        for(int i = start; i < nums.size(); ++i)
        {
            swap(nums[i], nums[start]);
            nowResult.push_back(nums[start]);
            dfs(nums, start+1, nowResult);
            nowResult.erase(nowResult.end() - 1);
            swap(nums[i], nums[start]);
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> nowResult;
        dfs(nums, 0, nowResult);
        return result;
    }

private:
    vector<vector<int>> result;

};