/*
    Title:          114.FlattenBinaryTreetoLinkedList.cpp
    Update date:    2022/04/27
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
    TreeNode* flattenCore(TreeNode* root)
    {
        if(!root)
            return NULL;

        // if no subtree, the last node is the root itself.
        if(!root->left && !root->right)
            return root;

        TreeNode* leftEnd = NULL;
        TreeNode* rightEnd = NULL;

        if(root->left)
            leftEnd = flattenCore(root->left);
        if(root->right)
            rightEnd = flattenCore(root->right);
        TreeNode* originRight = root->right;

        // if no left tree, the root's next node is the right,
        // thus there is no need to change.
        if(root->left)
        {
            root->right = root->left;
            root->left = NULL;
            leftEnd->right = originRight;
        }

        // if no right tree, the last node is from the left tree.
        return !rightEnd ? leftEnd : rightEnd;
    }

    void flatten(TreeNode* root) 
    {
        flattenCore(root);
    }
};