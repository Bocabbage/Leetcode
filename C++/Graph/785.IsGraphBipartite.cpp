/*
    Title:          785.IsGraphBipartite.cpp
    Update date:    2022/04/25
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // 0 --  not selected
        // 1 --  A
        // -1 -- B
        vector<int> currentSet(graph.size(), 0);
        int finishDivide = 0;
        queue<int> waitFinishQueue;
        waitFinishQueue.push(0);
        while(finishDivide < graph.size())
        {
            int i;
            if(waitFinishQueue.empty())
            {
                for(int idx = 0; idx < graph.size(); ++idx)
                {
                    if(currentSet[idx] == 0)
                    {
                        i = idx;
                        break;
                    }
                }
            }
            else
            {
                i = waitFinishQueue.front();
                waitFinishQueue.pop();
            }
            

            if(currentSet[i] != 0)
            {
                for(auto &j: graph[i])
                {
                    if(currentSet[j] == 0)
                    {
                        currentSet[j] = -currentSet[i];
                        waitFinishQueue.push(j);
                    }
                    else if(currentSet[j] == currentSet[i])
                        return false;
                }
            }
            else
            {
                int setShouldIn = 1;
                for(auto &j: graph[i])
                {
                    if(currentSet[j] != 0)
                    {
                        setShouldIn = -currentSet[j];
                        break;
                    }
                }

                currentSet[i] = setShouldIn;
                for(auto &j: graph[i])
                {
                    if(currentSet[j] == 0)
                    {
                        currentSet[j] = -currentSet[i];
                        waitFinishQueue.push(j);
                    }
                    else if(currentSet[j] == currentSet[i])
                        return false;
                }
            }

            finishDivide++;
        }

        return true;
    }
};