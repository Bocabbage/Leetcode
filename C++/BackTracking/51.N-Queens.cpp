/*
    Title:          51.N-Queens.cpp
    Update date:    2022/02/03
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    vector<vector<string>> solveNQueensCore(
        int n,
        int row,
        vector<bool>& hasQueen)
    {
        vector<vector<string> > res;
        
        if(row < 0)
            return res;
        
        for(int k = 0; k < n; ++k)
        {
            bool fail = false;
            
            // check col & diag
            for(int f_row = row+1; f_row < n; ++f_row)
            {
                if(
                    hasQueen[f_row*n + k] ||
                    (k-(f_row-row) >= 0 && hasQueen[f_row*n + k-(f_row-row)]) ||
                    (k+(f_row-row) < n  && hasQueen[f_row*n + k+(f_row-row)])
                  )
                {
                    fail = true;
                    break;
                }
            }
                
            if(!fail)
            {
                if(row == 0)
                {
                    // recursive end
                    string nowRowRes(n, '.');
                    nowRowRes[k] = 'Q';
                    vector<string> nres;
                    nres.emplace_back(std::move(nowRowRes));
                    res.emplace_back(std::move(nres));
                    return res;
                }
                
                hasQueen[row*n + k] = true;

                auto subres = solveNQueensCore(n, row-1, hasQueen);
                if(!subres.empty())
                {
                    string nowRowRes(n, '.');
                    nowRowRes[k] = 'Q';
                    for(auto &sub: subres)
                        sub.push_back(nowRowRes);
                    for(auto &nres: subres)
                        res.push_back(nres);
                }
                
                hasQueen[row*n + k] = false;
                
            }
        }
        
        return res;
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<bool> hasQueen(n*n, false);
        return solveNQueensCore(n, n-1, hasQueen);      
    }
};