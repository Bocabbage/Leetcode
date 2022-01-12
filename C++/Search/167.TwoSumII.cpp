/*
    Title:          167.TwoSumII.cpp
    Update date:    2022/01/06
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        for(int i = 0; i < nums.size(); ++i)
        {
        	auto partner = hash_table.find(target-nums[i]);
        	if(partner != hash_table.end())
        	{
        		return { partner->second, i+1 };
        	}
        	else
        		hash_table[nums[i]] = i + 1;
        }

        return {0, 0};
    }
};