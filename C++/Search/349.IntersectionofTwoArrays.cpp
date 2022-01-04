/*
    Title:          349.IntersectionofTwoArrays.cpp
    Update date:    2022/01/05
    Author:         Zhuofan Zhang
*/

// Method 1:
class Solution {
public:
    bool binarySearch(vector<int>& numbers, int target)
    {
        int lo = 0;
        int hi = numbers.size() - 1;
        int mid = -1;
        while(lo<=hi)
        {
            mid = (lo+hi)>>1;
            if(numbers[mid] == target)
                return true;
            else if(numbers[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        bool bitmap[1001] = { false };
        std::sort(nums2.begin(), nums2.end());

        for(auto &n: nums1)
        {
            if(bitmap[n])
                continue;

            bitmap[n] = true;

            if(binarySearch(nums2, n))
                res.push_back(n);
        }

        return res;
    }
};

// Method 2:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> existed(1001);
        for(auto n:nums1)
            existed[n] = true;
        set<int> ans;
        for(auto n:nums2)
            if(existed[n])
                ans.insert(n);
        return vector<int>{begin(ans), end(ans)};
    }
};