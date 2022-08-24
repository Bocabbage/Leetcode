/*
    Title:          399.EvaluateDivision.cpp
    Update date:    2022/08/24
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    using pairVector = vector<pair<string, double>>;

    double dfs(
        const string& curr,
        const string& dst,
        unordered_map<string, pairVector>& graph,
        unordered_set<string>& visited,
        double currVal
    )
    {
        if(graph.find(curr) == graph.end() || graph.find(dst) == graph.end())
            return -1.0;

        if(curr == dst)
            return currVal;

        if(visited.find(curr) != visited.end())
            return -1.0;
        
        visited.insert(curr);

        for(int i = 0; i < graph[curr].size(); ++i)
        {
            double tmpRes = dfs(
                graph[curr][i].first, dst, 
                graph, 
                visited,
                currVal * graph[curr][i].second
            );

            if(tmpRes > 0)
                return tmpRes;

        }

        visited.erase(curr);

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations, 
        vector<double>& values, 
        vector<vector<string>>& queries
    ) 
    {
        unordered_map<string, pairVector> graph;
        for(int i = 0; i < equations.size(); ++i)
        {
            auto &e = equations[i];
            if(graph.find(e[0]) == graph.end())
                graph[e[0]] = pairVector{pair<string, double>{e[1], values[i]}};
            else
                graph[e[0]].push_back({e[1], values[i]});
            
            if(graph.find(e[1]) == graph.end())
                graph[e[1]] = pairVector{pair<string, double>{e[0], 1.0 / values[i]}};
            else
                graph[e[1]].push_back({e[0], 1.0 / values[i]});
        }

        vector<double> res(queries.size(), 0);
        for(int i = 0; i < queries.size(); ++i)
        {
            unordered_set<string> visited;
            res[i] = dfs(queries[i][0], queries[i][1], graph, visited, 1.0);
        }

        return res;
    }
};