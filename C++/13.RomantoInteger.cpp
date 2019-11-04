/*
    Title:          13.RomantoInteger.cpp
    Update date:    2019/11/04
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int romanToInt(string s) 
    {
        /* 
            Method1:(24.69%,31.37%)
            But I wouldn't like to change the code
            to the ugly branch struct to speed it up.
            
            Method2:(77.36%,57.84%)
            Use the int array to reduce the cost does the 'unordered_map' use.
        */
        int res = 0;
        auto slen = s.length();
        // unordered_map<char,int> rank = {
        //     {'I',0},
        //     {'V',1},
        //     {'X',2},
        //     {'L',3},
        //     {'C',4},
        //     {'D',5},
        //     {'M',6}
        // };
        // int basis[] = {1,5,10,50,100,500,1000};
        
        int rank[128];
        rank['I'] = 1;
        rank['V'] = 5;
        rank['X'] = 10;
        rank['L'] = 50;
        rank['C'] = 100;
        rank['D'] = 500;
        rank['M'] = 1000;
        
        
        size_t i = 0;
        while(i < slen)
        {
            if(rank[s[i]] < rank[s[i+1]])
            {
                // res += basis[rank[s[i+1]]] - basis[rank[s[i]]];
                res += rank[s[i+1]] - rank[s[i]];
                i += 2;
            }
            else
            {
                // res += basis[rank[s[i]]];
                res += rank[s[i]];
                i++;
            }
        }

        return res;
    }
};