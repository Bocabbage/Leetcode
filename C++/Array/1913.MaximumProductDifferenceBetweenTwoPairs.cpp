/*
    Title:          1913.MaximumProductDifferenceBetweenTwoPairs.cpp
    Update date:    2021/11/05
    Author:         Zhuofan Zhang
*/

// 1. SORT is not necessary
// 2. max/min should be select independently
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max = 0, second_max = -1;
        int min = INT_MAX-1, second_min = INT_MAX;
        for(auto &n: nums)
        {
            if(n > max)
                second_max = max, max = n;
            else if(n > second_max)
                second_max = n;
            
            if(n < min)
                second_min = min, min = n;
            else if(n < second_min)
                second_min = n;
        }
        
        return max*second_max - min*second_min;
    }
};