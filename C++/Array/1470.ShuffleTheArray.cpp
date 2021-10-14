/*
    Title:          1470.ShuffleTheArray.cpp
    Update date:    2020/10/13
    Author:         Zhuofan Zhang
    Annotation:     About how to carry the 2 value together and separate them when needed.
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // The problem constraint the nums[i] in [1, 1000]
        int magicNum = 2000; 
        for (int i = 0; i < n; ++i) {
            nums[i] += nums[i+n] * magicNum;
        }
        for (int i = n-1; i >= 0; --i) {
            nums[i*2+1] = nums[i] / magicNum;
            nums[i*2] = nums[i] % magicNum;
        }
        
        return nums;
    }
};