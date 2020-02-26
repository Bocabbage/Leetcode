/*
    Title:          26.RemoveDuplicatesfromSortedArray.cpp
    Update date:    2020/2/26
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        /*
        auto p = nums.begin();
        auto q = p + 1;
        while(p != nums.end())
        {
            while(q != nums.end() && *q == *p)
                ++q;
            
            p = nums.erase(p+1, q);
            q = p + 1;
        }
        
        return nums.size();
        */
        
        // submission(94.27%, 87.50%)
        if(nums.size() == 0)
            return 0;
        auto p = nums.begin();
        auto q = p + 1;
        auto _end = nums.end();
        while(q != _end)
        {
            if(*p != *q)
            {
                p++;
                *p = *q;
            }
            q++;
        }
        nums.erase(p+1, _end);
        return nums.size();
        
    }
};