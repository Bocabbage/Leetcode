/*
    Title:          53.MaximumSubarray.cpp
    Update date:    2020/08/24
    Author:         Zhuofan Zhang
*/

// Method1: Dynamic-programming
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        size_t len = nums.size();
        int* dp = new int[len];
        dp[0] = nums[0];
        int result = dp[0];
        
        for(size_t i = 1; i < len; ++i)
        {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            result = result < dp[i] ? dp[i] : result;
        }
        
        return result;
        
    }
};

// Method2: Segment Tree
class Solution {
public:
    struct Status
    {
        int lSum;
        int rSum;
        int iSum;
        int mSum;
    };

    Status pushUp(
        const Status& lInt,
        const Status& rInt
    )
    {
        Status resInt;
        resInt.iSum = lInt.iSum + rInt.iSum;
        resInt.lSum = max(lInt.lSum, lInt.iSum + rInt.lSum);
        resInt.rSum = max(rInt.rSum, rInt.iSum + lInt.rSum);
        resInt.mSum = max(max(lInt.mSum, rInt.mSum), lInt.rSum + rInt.lSum);
        return resInt;
    }

    Status get(
        const vector<int>& nums,
        int begin, 
        int end
    )
    {
        if(begin == end)
            return Status{nums[begin], nums[begin], nums[begin], nums[begin]};
        
        int mid = begin + ((end-begin) >> 1);

        Status lInt = get(nums, begin, mid);
        Status rInt = get(nums, mid+1, end);
        return pushUp(lInt, rInt);
    }

    int maxSubArray(vector<int>& nums) 
    {
        return get(nums, 0, nums.size()-1).mSum;
    }
};