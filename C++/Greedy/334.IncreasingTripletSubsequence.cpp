/*
    Title:          334.IncreasingTripletSubsequence.cpp
    Update date:    2022/06/22
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int first = nums[0], second = INT_MAX;
        for(auto &n: nums)
        {
            if(n > second)
                return true;
            else if(n > first)
                second = n;
            else
                first = n;
        }

        return false;
    }
};