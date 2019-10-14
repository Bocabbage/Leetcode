/*
    Title:          15.3Sum.cpp
    Update date:    2019/10/14
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        // Special Situation:
        if(nums.size() < 3)
            return res;
        // if(nums.size() == 3)
        // {
        //     int sum = 0;
        //     for(auto i = nums.cbegin();i != nums.cend();++i)
        //         sum += *i;
        //     if(sum)
        //         return res;
        //     else
        //     {
        //         vector<vector<int>> res;
        //         res.push_back(nums);
        //         return res;
        //     }
        // }
        
        /* Method: After Sorting */
        std::sort(nums.begin(),nums.end());
        const auto last = nums.end() - 1;
        
        auto p = nums.begin();
        auto q = nums.end() - 2;
        int last_p = *p - 1;
        for( ;p < last && *p < 0;++p )
        {
            q = nums.end() - 2;
            
            if( *p+*q+*last < 0 || *p == last_p )
                continue;
            else
            {
/*
                Method1: Use Binary-Search to search the last value
                Worst situation(in this section): O(nlgn)
                Submission: (10.79%, 100%)
*/
//                 int last_q = *last + 1; 
//                 while(q > p)
//                 {
                      
//                     if( *q == last_q )
//                     {
//                         q--;
//                         continue;
//                     }
//                     // The 'binary_search' is the bottleneck.
//                     if(std::binary_search(q+1,nums.end(),-(*p+*q)))
//                     {
//                         last_q = *q;
//                         last_p = *p;
//                         res.push_back({last_p,last_q,-(last_p+last_q)});
//                     }
//                     q--;
//                 }

/*
                Method2: reduced the problem into '2Sum', use 2-pointers method.
                Worst situation(in this section): O(n)
                Submission: (83.39%, 100%)
*/               
                q = p + 1;
                auto r = last;
                while(q < r)
                {
                    if(*p+*q+*r < 0)q++;
                    else if(*p+*q+*r > 0)r--;
                    else
                    {
                        res.push_back({*p,*q,*r});
                        q++;r--;
                        while(q < r && *q == *(q-1))q++;
                        while(q < r && *r == *(r+1))r--;
                    }
                }
            }
             
            last_p = *p;
        }
        
        if(p != last)
        {
            // May have [0,0,0]
            size_t counts = 0;
            while(p!=nums.end() && *p == 0)
            {
                if(++counts == 3)break;
                ++p;
            }
                
            if(counts == 3)
                res.push_back({0,0,0});
            
        }
            
        return res;
    }

};