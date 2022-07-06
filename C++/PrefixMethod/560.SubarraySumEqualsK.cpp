/*
    Title:          560.SubarraySumEqualsK.cpp
    Update date:    2022/07/06
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int result = 0;
        int currVal = 0;
        for(auto &n: nums)
        {
            currVal += n;
            if(prefix.find(currVal-k) != prefix.end())
                result += prefix[currVal-k];
            prefix[currVal]++;
        }

        return result;
    }
};