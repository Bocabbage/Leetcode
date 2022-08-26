/*
    Title:          424.LongestRepeatingCharacterReplacement.cpp
    Update date:    2022/08/26
    Author:         Zhuofan Zhang
*/

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int left = 0, right = 0;
        int alphaCounts[26] = {0};
        int res = 0;

        // 维护的[left, right)区间长度为非递减的
        //（每次移动都伸长/长度不变）
        while(right < s.length())
        {
            alphaCounts[s[right]-'A']++;
            // 只有新一轮增加的字符s[right]数量变化，
            // 若产生新最大值也尽可能从其数量变化产生
            res = max(res, alphaCounts[s[right]-'A']);
            if(right - left + 1 - res > k)
            {
                // 该分支只有可能在res > alphaCounts[s[right]-'A'] 时发生
                alphaCounts[s[left]-'A']--;
                left++;
            }
            right++;
        }

        // 此时right停留在end处，因此：(right - left + 1) - 1
        return right - left;
    }
};