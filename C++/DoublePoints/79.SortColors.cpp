/*
    Title:          79.SortColors.cpp
    Update date:    2022/06/10
    Author:         Zhuofan Zhang
*/

/* Method 1 */
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        vector<int> stat(3, 0);
        for(auto &n: nums)
            stat[n]++;
        
        int nowStatIdx = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            while(stat[nowStatIdx] == 0)
                nowStatIdx++;
            
            nums[i] = nowStatIdx;
            stat[nowStatIdx]--;
        }
    }
};



/* Method 2 */
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int leftp = -1, rightp = nums.size();
        for(int i = 0; i < rightp; ++i)
        {
            while(nums[i] != 1 && i < rightp && i > leftp)
            {
                if(nums[i] == 0)
                {
                    leftp++;
                    swap(nums[leftp], nums[i]);
                }
                else
                {
                    rightp--;
                    swap(nums[rightp], nums[i]);
                }
            }
        }    
    }
};