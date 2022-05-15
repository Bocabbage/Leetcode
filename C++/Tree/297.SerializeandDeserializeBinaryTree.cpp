/*
    Title:          297.SerializeandDeserializeBinaryTree.cpp
    Update date:    2022/04/29
    Author:         Zhuofan Zhang
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeCore(TreeNode *root, string &res)
    {
        if(!root)
        {
            res += "$,";
            return;
        }
        
        res += to_string(root->val);
        res += ',';

        serializeCore(root->left, res);
        serializeCore(root->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string res;
        if(!root)
            return res;
        serializeCore(root, res);
        return res;
    }

    void deserializeCore(vector<TreeNode*> &nodes, int &idx)
    {
        if(idx >= nodes.size()-2 || nodes[idx] == NULL)
        {
            // [nodes.size()-2, nodes.size()) must be NULL or not-null leaf
            idx++;  // this node has been used from now
            return;
        }

        int originIdx = idx;
        idx++;                  // this node has been used from now
        // left subtree
        nodes[originIdx]->left = nodes[idx];
        deserializeCore(nodes, idx);
        nodes[originIdx]->right = nodes[idx];
        deserializeCore(nodes, idx);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.empty())
            return NULL;
        vector<TreeNode*> nodes;
        int start = 0;
        int curr = 0;

        while(curr < data.size())
        {
            while(curr < data.size() && data[curr] != ',')
                curr++;
            
            if(data[start] == '$')
            {
                nodes.push_back(NULL);
            }
            else
            {
                int val = stoi(data.substr(start, curr-start));
                TreeNode *newNode = new TreeNode(val);
                nodes.push_back(newNode);
            }
            start = curr+1;
            curr = start;
        }

        int idx = 0;
        deserializeCore(nodes, idx);
        return nodes[0];
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));