/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums,int start,int end)
    {
        if(start>=end)return nullptr;
        //vector<int>::iterator max = std::max_element(nums.begin()+start,nums.begin()+end);
        //TreeNode* root = new TreeNode(*max);
        int Max=nums[start];
        int MaxIndex=start;
        for(size_t i=start+1;i<end;++i)
            if(nums[i]>Max)Max=nums[i],MaxIndex=i;
        TreeNode* root = new TreeNode(nums[MaxIndex]);
        root->left = constructMaximumBinaryTree(nums,start,MaxIndex);
        root->right = constructMaximumBinaryTree(nums,MaxIndex+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return constructMaximumBinaryTree(nums,0,nums.size());
    }
    
};