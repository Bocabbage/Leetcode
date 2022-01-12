/*
    Title:          110.BalancedBinaryTree.cpp
    Update date:    2022/01/10
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
	int maxDepth(TreeNode* node, int depth)
	{
		if(!node)
			return depth; 
		int left_depth = maxDepth(node->left, depth+1);
		int right_depth = maxDepth(node->right, depth+1);

		if(abs(left_depth-right_depth) > 1)
			return -1;
		else
			return max(left_depth, right_depth);

	}

    bool isBalanced(TreeNode* root) {
    	if(!root)
    		return true;
        
        return maxDepth(root, 1) > 0;
    }
};