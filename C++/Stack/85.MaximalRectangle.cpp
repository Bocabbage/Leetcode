/*
    Title:          85.MaximalRectangle.cpp
    Update date:    2022/06/20
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

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
    	int result = 0;
    	vector<int> lineHeight(matrix[0].size(), 0);

    	for(int i = 0; i < matrix.size(); ++i)
    	{
    		for(int j = 0; j < lineHeight.size(); ++j)
    		{
    			if(matrix[i][j] == '0')
    				lineHeight[j] = 0;
    			else
    				lineHeight[j] += matrix[i][j] - 48;
    		}

    		result = max(result, largestRectangleArea(lineHeight));

    	}

    	return result;
    }
};