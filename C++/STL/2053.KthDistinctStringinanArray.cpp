/*
    Title:          2053.KthDistinctStringinanArray.cpp
    Update date:    2021/11/18
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string>ans;
        string x ="";
      // unordered_map 是 Hash Table 实现
      // 该实现的行为确定性存疑
      unordered_map<string,int>mp;
        for(auto s:arr){
            mp[s]++;
        }
      for(auto s:arr){
        if(mp[s]==1) ans.push_back(s);
        }
        if(ans.size()>=k) return ans[k-1];
        else 
            return x;
    }

    // old version
    // map 是红黑树实现
    // string kthDistinct(vector<string>& arr, int k) {
    //     map<string, int> dist_set;
    //     vector<int> dist_idx;
    //     for(size_t i = 0; i < arr.size(); ++i)
    //     {
    //         auto finder = dist_set.find(arr[i]);
    //         if(finder == dist_set.end())
    //             dist_set.insert({arr[i], i});
    //         else
    //             finder->second = -1;
    //     }
    //     for(auto &m: dist_set)
    //     {
    //         if(m.second >= 0)
    //             dist_idx.push_back(m.second);
    //     }

    //     sort(dist_idx.begin(), dist_idx.end());
    //     if(dist_idx.size() < k)
    //         return "";
    //     return arr[dist_idx[k-1]];
    // }
};