/*
    Title:          47.PermutationsII.cpp
    Update date:    2022/05/15
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    void dfs(
        vector<int>& nums,
        vector<int> nowResult,
        vector<bool> &checked
    )
    {

        if(nowResult.size() == nums.size())
        {
            result.push_back(std::move(nowResult));
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(checked[i])
                continue;

            if(
                i > 0 && 
                (!checked[i-1] && nums[i] == nums[i-1])
            )continue;

            if(i == nums.size())
                break;

            checked[i] = true;
            nowResult.push_back(nums[i]);
            dfs(nums, nowResult, checked);
            nowResult.erase(nowResult.end()-1);
            checked[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> nowResult;
        vector<bool> checked(nums.size(), false);
        dfs(nums, nowResult, checked);
        return result;
    }

private:
    vector<vector<int>> result;

};

