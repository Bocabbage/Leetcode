/*
    Title:          538.ConvertBSTtoGreaterTree.cpp
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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;

        stack<TreeNode *> stk;
        TreeNode *cur_node = root;
        bool backtrack = false;

        while(cur_node)
        {
            if(cur_node->right && !backtrack)
            {
                stk.push(cur_node);
                cur_node = cur_node->right;
            }
            else
            {
                sum += cur_node->val;
                cur_node->val = sum;
    
                if(cur_node->left)
                {
                    cur_node = cur_node->left;
                    backtrack = false;
                }
                else if(stk.empty())
                    break;
                else
                {
                    cur_node = stk.top();
                    stk.pop();
                    backtrack = true;
                }
                
            }
        }
        
        return root;
    }
};