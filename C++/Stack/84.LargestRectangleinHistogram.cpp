/*
    Title:          84.LargestRectangleinHistogram.cpp
    Update date:    2022/06/13
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> monoToneStk;
        int result = 0;
        int sz = heights.size();
        for(int i = 0; i < sz; ++i)
        {
            while(!monoToneStk.empty() && heights[monoToneStk.top()] > heights[i])
            {
                int height = heights[monoToneStk.top()];
                monoToneStk.pop();

                int weight = i;
                if(!monoToneStk.empty())
                    weight = i - monoToneStk.top() - 1;

                result = max(result, weight * height);
            }

            monoToneStk.push(i);
        }

        while(!monoToneStk.empty())
        {
            int height = heights[monoToneStk.top()];
            monoToneStk.pop();
            
            int weight = sz;
            if(!monoToneStk.empty())
                weight = sz - monoToneStk.top() - 1;
            result = max(result, weight * height);
        }

        return result;
    }
};