/*
    Title:          208.ImplementTrie.cpp
    Update date:    2022/05/31
    Author:         Zhuofan Zhang
*/

struct TrieNode
{
    unordered_map<char, TrieNode*> subs;
};

class Trie 
{
public:
    Trie():
    root_(new TrieNode)
    {

    }
    
    void insert(string word) 
    {
        TrieNode* p = root_;
        for(auto &c: word)
        {
            if(p->subs.find(c) == p->subs.end())
            {
                TrieNode *newNode = new TrieNode;
                p->subs[c] = newNode;
            }

            p = p->subs[c];
        }

        if(p->subs.find('$') == p->subs.end())
            p->subs['$'] = nullptr;
    }
    
    bool search(string word) 
    {
        TrieNode* p = root_;
        for(auto &c: word)
        {
            if(p->subs.find(c) == p->subs.end())
                return false;
            p = p->subs[c];
        }

        return p->subs.find('$') != p->subs.end();
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* p = root_;
        for(auto &c: prefix)
        {
            if(p->subs.find(c) == p->subs.end())
                return false;
            p = p->subs[c];
        }

        return true;
    }

private:
    TrieNode* root_;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */