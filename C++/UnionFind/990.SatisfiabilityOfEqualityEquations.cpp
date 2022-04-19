/*
    Title:          990.SatisfiabilityOfEqualityEquations.cpp
    Update date:    2022/04/15
    Author:         Zhuofan Zhang
*/
class UF
{

public:
    UF(int size)
    :unionFind_(size, 0),
     treeSize_(size, 1)
    {
        for(int i = 0; i < size; ++i)
            unionFind_[i] = i;
    }

    void connect(int p, int q)
    {
        int pRoot = findRoot(p);
        int qRoot = findRoot(q);
        if(pRoot == qRoot)
            return;
        else if(treeSize_[pRoot] > treeSize_[qRoot])
        {
            unionFind_[qRoot] = pRoot;
            treeSize_[pRoot] += treeSize_[qRoot];
        }
        else
        {
            unionFind_[pRoot] = qRoot;
            treeSize_[qRoot] += treeSize_[pRoot];
        }
            
    }
    bool isConnected(int p, int q)
    {
        int pRoot = findRoot(p);
        int qRoot = findRoot(q);
        return pRoot == qRoot;
    }
    int findRoot(int p)
    {
        int prefix = p;
        while(unionFind_[prefix] != prefix)
        {
            unionFind_[prefix] = unionFind_[unionFind_[prefix]];
            prefix = unionFind_[prefix];
        }

        return prefix;
    }

private:
    vector<int> unionFind_;
    vector<int> treeSize_;

};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        vector<pair<char, char>> unEqualSet;
        for(auto &eq: equations)
        {
            if(eq[1] == '!')
            {
                unEqualSet.push_back(make_pair(eq[0], eq[3]));
            }
            else
                uf.connect(eq[0]-97, eq[3]-97);
        }

        for(auto &ueq: unEqualSet)
        {
            if(uf.isConnected(ueq.first - 97, ueq.second - 97))
                return false;
        }

        return true;
    }
};