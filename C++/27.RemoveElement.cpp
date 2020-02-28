/*
    Title:          27.RemoveElement.cpp
    Update date:    2020/2/28
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
       // submission(100.00%, 100.00%)
       if(nums.size() == 0)
           return 0;
        if(nums.size() == 1 && nums[0] == val)
        {
            nums.clear();
            return 0;
        }
            
            
        auto p = nums.begin(), q = nums.end() - 1;
        while(p <= q)
        {
            if(*p == val)
            {
                while(q > p && *q == val)
                    q--;
                *p = *(q--);
            }
               
            p++;
        }
        nums.erase(q+1, nums.end());
        return nums.size();
    }
};