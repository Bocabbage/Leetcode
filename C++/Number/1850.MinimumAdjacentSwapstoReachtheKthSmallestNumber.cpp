/*
    Title:          1850.MinimumAdjacentSwapstoReachtheKthSmallestNumber.cpp
    Update date:    2021/11/18
    Author:         Zhuofan Zhang
*/
class Solution {
public:    
    int getMinSwaps(string num, int k) {
        int steps = 0;
        string k_swi = num;
        while(k--)
            next_permutation(k_swi.begin(), k_swi.end());
        for(int i = 0; i < num.size(); ++i)
        {
            int j = i;
            while(j < num.size())
            {
                if(num[j] == k_swi[i])
                    break;
                ++j;
            }
            
            steps += j - i;
            
            while(j > i)
            {
                swap(num[j], num[j-1]);
                j--;
            }
        }
        
        return steps;
    }
};