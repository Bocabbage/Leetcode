/*
    Title:          1859. SortingtheSentence.cpp
    Update date:    2021/10/18
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Method 1:
        // int result = 0;
        // for(size_t i = 0; i < nums.size() - 1; ++i)
        // {
        //     for(size_t j = i + 1; j < nums.size(); ++j)
        //         if(nums[i] == nums[j])
        //             result++;
        // }
        
        // return result;
        int res = 0;
        unordered_map<int, int> count;
        for (int a: nums) {
            res += count[a]++;
        }
        return res;

    }
};