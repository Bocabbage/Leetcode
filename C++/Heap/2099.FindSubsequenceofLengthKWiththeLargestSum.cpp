/*
    Title:          2099.FindSubsequenceofLengthKWiththeLargestSum.cpp
    Update date:    2022/01/06
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    struct minCompare
    {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int> > max_heap;
        for(int i = 0; i < nums.size(); ++i)
            max_heap.push(make_pair(nums[i], i));
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, minCompare > min_idx_heap;
        
        while(k > 0)
        {
            min_idx_heap.push(max_heap.top());
            max_heap.pop();
            k--;
        }
        
        while(!min_idx_heap.empty())
        {
            res.push_back(min_idx_heap.top().first);
            min_idx_heap.pop();
        }
        
        return res;
            
    }
};