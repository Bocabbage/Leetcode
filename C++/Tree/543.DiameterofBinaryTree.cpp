/*
    Title:          543.DiameterofBinaryTree.cpp
    Update date:    2022/04/25
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
    int getMaxDiameter(TreeNode *root, int &maxResult)
    {
        if(!root)
            return 0;

        int leftPath = getMaxDiameter(root->left, maxResult);
        int rightPath = getMaxDiameter(root->right, maxResult);
        int nowMaxDiameter = leftPath + rightPath + 1;

        if(nowMaxDiameter > maxResult)
            maxResult = nowMaxDiameter;
        
        return leftPath > rightPath ? leftPath + 1 : rightPath + 1;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxResult = 0;  // node-nums
        getMaxDiameter(root, maxResult);
        return maxResult - 1;
    }
};