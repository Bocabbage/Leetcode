/*
    Title:          739.DailyTemperatures.cpp
    Update date:    2022/07/08
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int> monoStk;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); ++i)
        {
            while(!monoStk.empty() && temperatures[monoStk.top()] < temperatures[i])
            {
                result[monoStk.top()] = i - monoStk.top();
                monoStk.pop();
            }
            
            monoStk.push(i);
        }

        return result;
    }
};