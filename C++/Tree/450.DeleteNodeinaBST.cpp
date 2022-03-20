/*
    Title:          450.DeleteNodeinaBST.cpp
    Update date:    2022/03/20
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val > key) 
            root->left = deleteNode(root->left, key);
        if(root->val < key) 
            root->right = deleteNode(root->right, key);
        if(root->val == key){
            if(!root->left && !root->right){
                return nullptr;
            }
            else if(root->left && !root->right){
                return root->left;
            }
            else if(!root->left && root->right){
                return root->right;
            }
            else if(root->left && root->right){
                TreeNode* new_node = root->right;
                while(new_node && new_node->left){
                    new_node = new_node->left;
                }
                new_node->left = root->left;
                root->left = nullptr;

                return root->right;
            }
        }

        return root;
    }

};