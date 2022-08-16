/*
    Title:          437.PathSumIII.cpp
    Update date:    2022/07/06
    Author:         Zhuofan Zhang
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(
        TreeNode* now,
        long long currVal,
        int targetSum
    )
    {
        if(!now)
            return 0;
        
        int ret = 0;
        currVal += now->val;
        // sub-path from the root
        if(prefix.find(currVal - targetSum) != prefix.end())
            ret = prefix[currVal - targetSum];
        
        prefix[currVal]++;
        ret += dfs(now->left, currVal, targetSum);
        ret += dfs(now->right, currVal, targetSum);
        prefix[currVal]--;
        
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) 
    {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }

private:
    unordered_map<int, int> prefix;
};