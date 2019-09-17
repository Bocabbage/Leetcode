/*
    Title:          131.PalindromePartitioning.cpp
    Update date:    2019/09/17
    Author:         Zhuofan Zhang
*/

/* Method1: Back-Tracking */
class Solution 
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> subres;
        if(s.size()<=1)
        {
            subres.push_back(s);
            res.push_back(subres);
            return res;
        }
        
        // trace: a stack recording the partition-idx
        vector<size_t> trace;
        size_t idx=1;
        trace.push_back(0);
        trace.push_back(idx++);
        while(!(trace.size()==1 && idx > s.size()))
        {
            if(trace.back()==s.size())
            {
                // Successfully find a partition
                subres.clear();
                for(size_t j=1;j<trace.size();++j)
                    subres.push_back(s.substr(trace[j-1],trace[j]-trace[j-1]));
                res.push_back(subres);
                trace.pop_back();
                idx = trace.back()+1;
                trace.pop_back();
                if(trace.empty())
                    break;
            }
            else if(idx > s.size())
            {
                // Failed to find a partition,
                // back to the last step
                idx = trace.back()+1;
                trace.pop_back();
            }
            else
            {
                // find new parlindrome substring
                // and push the step into the stack
                size_t begin = trace.back();
                size_t end = idx-1;
                while(begin<end)
                {
                    if(s[begin]!=s[end])
                        break;
                    begin++;end--;
                }
                    
                if(begin>=end)
                    trace.push_back(idx);
                idx++;
            }
        }
        
        return res;
    }
    
};