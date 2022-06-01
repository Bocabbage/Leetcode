/*
    Title:          89.GrayCode.cpp
    Update date:    2022/05/31
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};
