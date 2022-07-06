/*
    Title:          337.HouseRobberIII.cpp
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
    void dfs(
        unordered_map<TreeNode*, int>& f,
        unordered_map<TreeNode*, int>& g,
        TreeNode* now
    )
    {
        int left_f = 0, left_g = 0;
        int right_f = 0, right_g = 0;

        if(now->left)
        {
            dfs(f, g, now->left);
            left_f = f[now->left];
            left_g = g[now->left];
        }

        if(now->right)
        {
            dfs(f, g, now->right);
            right_f = f[now->right];
            right_g = g[now->right];
        }

        f[now] = now->val + left_g + right_g;
        g[now] = max(left_f, left_g) + max(right_f, right_g);
    }

    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode*, int> f, g;
        dfs(f, g, root);
        return max(f[root], g[root]);
    }
};