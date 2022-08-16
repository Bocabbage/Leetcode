/*
    Title:          347.TopKFrequentElements.cpp
    Update date:    2022/06/27
    Author:         Zhuofan Zhang
*/
struct Cmp
{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.second <= rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> result;
        unordered_map<int, int> hash;
        for(auto &n: nums)
        {
            if(hash.find(n) == hash.end())
                hash[n] = 1;
            else
                hash[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> maxHeap;
        for(auto &it: hash)
        {
            maxHeap.push(it);
        }

        for(int i = 0; i < k; ++i)
        {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return result;
            
    }
};