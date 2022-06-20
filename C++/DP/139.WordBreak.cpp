/*
    Title:          139.WordBreak.cpp
    Update date:    2022/06/14
    Author:         Zhuofan Zhang
*/
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

struct TrieTreeNode
{
	TrieTreeNode(bool isleaf):
	leaf(isleaf),
	sub(26, nullptr)
	{

	}

	vector<TrieTreeNode*> sub;
	bool leaf;
};

class Solution {
public:
	bool dfs(
		const string& s,
		int idx,
		TrieTreeNode *current,
		TrieTreeNode *root,
		unordered_map<pair<int, TrieTreeNode*>, bool, pair_hash>& dp
	)
	{

		if(!current)
			return false;

		if(idx == s.length())
			return current->leaf;

		auto idxNodePair = make_pair(idx, current);

		if(dp.find(idxNodePair) != dp.end())
			return dp[idxNodePair];

		bool result;
		if(current->leaf)
		{
			result = dfs(s, idx+1, current->sub[s[idx]-97], root, dp) ||
				     dfs(s, idx, root, root, dp);
		}
		else
		{
			result = dfs(s, idx+1, current->sub[s[idx]-97], root, dp);
		}

		dp[idxNodePair] = result;
		return result;
	}

    bool wordBreak(string s, vector<string>& wordDict) 
    {
    	// construct the TrieTree
    	TrieTreeNode* root = new TrieTreeNode(false);

    	for(auto &w: wordDict)
    	{
    		TrieTreeNode* p = root;
    		for(int i = 0; i < w.size(); ++i)
    		{
    			if(!p->sub[w[i]-97])
    				p->sub[w[i]-97] = new TrieTreeNode(false);
    			p = p->sub[w[i]-97];
    		}
    		p->leaf = true;
    	}

    	unordered_map<pair<int, TrieTreeNode*>, bool, pair_hash> dp;
    	return dfs(s, 0, root, root, dp);
    }
};