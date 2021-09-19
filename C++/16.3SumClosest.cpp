/*
    Title:          16.3SumClosest.cpp
    Update date:    2021/09/04
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // First step: sort the nums
        std::sort(nums.begin(), nums.end());
        const int numsSize = nums.size();
        
        auto p = nums.begin();
        auto r = nums.end() - 1;
        
        if(*p + *(p+1) + *(p+2) >= target)
            return *p + *(p+1) + *(p+2);
        
        if(*r + *(r-1) + *(r-2) <= target)
            return *r + *(r-1) + *(r-2);
        
        auto q = nums.begin() + 1;
        int result = 30000;
        int nowResult, lastResult, qResult, qiResult;
        
        while(q < nums.end() - 1)
        {
            p = q - 1;
            r = q + 1;
            nowResult = *p + *q + *r;
            
            if(nowResult == target)
                return target;
            else if(nowResult < target)
            {
                while(nowResult < target && r < nums.end())
                {
                    nowResult = *p + *q + *r;
                    r++;
                }
                lastResult = (r - 2) > q ? *p + *q + *(r - 2) : nowResult;
                qResult = abs(lastResult - target) > abs(nowResult - target) ? nowResult : lastResult;
                if(nowResult == target)
                    return target;
                else if(nowResult > target)
                {
                    r--;
                    while(nowResult > target && p >= nums.begin())
                    {
                        nowResult = *p + *q + *r;
                        p--;
                    }
                    
                    if(nowResult == target)
                        return target;

                    lastResult = (p + 2) < q ? *(p + 2) + *q + *r : nowResult;
                    qiResult = abs(lastResult - target) > abs(nowResult - target) ? nowResult : lastResult;
                    qResult = abs(qResult - target) > abs(qiResult - target) ? qiResult : qResult;
                }
            }
            else
            {
                while(nowResult > target && p >= nums.begin())
                {
                    nowResult = *p + *q + *r;
                    p--;
                }
                lastResult = (p + 2) < q ? *(p + 2) + *q + *r : nowResult;
                qResult = abs(lastResult - target) > abs(nowResult - target) ? nowResult : lastResult;
                if(nowResult == target)
                    return target;
                else if(nowResult > target)
                {
                    p++;
                    while(nowResult < target && r < nums.end())
                    {
                        nowResult = *p + *q + *r;
                        r++;
                    }
                    
                    if(nowResult == target)
                        return target;

                    lastResult = (r - 2) > q ? *p + *q + *(r - 2) : nowResult;
                    qiResult = abs(lastResult - target) > abs(nowResult - target) ? nowResult : lastResult;
                    qResult = abs(qResult - target) > abs(qiResult - target) ? qiResult : qResult;
                }
            }
            
            result = abs(qResult - target) < abs(result - target) ? qResult : result;
            q++;
        }
        
        return result;
        
        
    }
};