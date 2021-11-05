/*
    Title:          1588.SumofAllOddLengthSubarrays.cpp
    Update date:    2021/11/05
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0,n=arr.size(),i;
        for(i =0;i<n;i++)
        {
            int contribution = ceil((i+1)*(n-i)/2.0); // ceil: 向上取整
            ans+=(contribution*arr[i]);
        }
        return ans;
    }
};