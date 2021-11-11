/*
    Title:          1605.FindValidMatrixGivenRowandColumnSums.cpp
    Update date:    2021/11/11
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(),vector<int>(colSum.size(),0));
        int n=rowSum.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<colSum.size();j++){
                if(rowSum[i]==0 || colSum[j]==0){
                }  
                else if(rowSum[i]<colSum[j]){
                    ans[i][j]=rowSum[i];
                    colSum[j]=colSum[j]-rowSum[i];
                    rowSum[i]=0;
                }
                else{
                    ans[i][j]=colSum[j];
                     rowSum[i]=rowSum[i]-ans[i][j];
                    colSum[j]=0; 
                }
            }
          
        }
        return ans;
    }
};