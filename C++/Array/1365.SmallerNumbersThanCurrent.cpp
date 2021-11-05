/*
    Title:          1365.SmallerNumbersThanCurrent.cpp
    Update date:    2021/10/19
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> sort_nums = nums;
        unordered_map<int, int> vi_map;
        sort(sort_nums.begin(), sort_nums.end());
        for(int i = nums.size() - 1; i >= 0; --i)
            vi_map[sort_nums[i]] = i;
        for(size_t i = 0; i < nums.size(); ++i)
            result[i] = vi_map[nums[i]];
            
//         vector<int> idx_sort(nums.size());
//         iota(idx_sort.begin(), idx_sort.end(), 0);
//         sort(idx_sort.begin(), idx_sort.end(), [&nums](int i1, int i2){return nums[i1] < nums[i2];});
        
//         int repetion = 1;
//         for(size_t i = 0; i < nums.size(); ++i)
//         {
//            if(i > 0 && nums[idx_sort[i]] == nums[idx_sort[i-1]])
//            {
//                result[idx_sort[i]] = i - repetion;
//                repetion++;
//            }
//             else
//             {
//                 result[idx_sort[i]] = i; 
//                 repetion = 1;
//             }
            
//         }
            
        return result;
    }
};