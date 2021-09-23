/*
    Title:          25.ReverseNodesInKGRoups.cpp
    Update date:    2019/09/23
    Author:         Zhuofan Zhang
    Latest Method:  Use Bool-Bucket
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode* emptyHead = new ListNode(0, head);
        ListNode* p = emptyHead;
        
        vector<ListNode *> group(k+1, nullptr);
        group[0] = emptyHead;
        int nowGroupNums = 0;
        
        while(p != nullptr)
        {
            if(nowGroupNums == k)
            {
                int lidx = 1, ridx = nowGroupNums;
                ListNode* tmp;

                while(ridx - lidx > 1)
                {
                    tmp = group[lidx];
                    group[lidx] = group[ridx];
                    group[ridx] = tmp;
                    
                    group[lidx-1]->next = group[lidx];
                    group[ridx-1]->next = group[ridx];
                    group[ridx]->next = group[lidx]->next;
                    group[lidx]->next = group[lidx+1];
                    
                    lidx++;
                    ridx--;
                }
                
                // // The mid 2 exchange
                if(ridx != lidx)
                {
                    tmp = group[lidx];
                    group[lidx] = group[ridx];
                    group[ridx] = tmp;
                    
                    group[lidx-1]->next = group[lidx];
                    group[ridx]->next = group[lidx]->next;
                    group[lidx]->next = group[ridx];
                    
                }
                
                nowGroupNums = 0;
                p = group[k];
                group[0] = p;
            }
            else
            {
                p = p->next;
                nowGroupNums++;
                group[nowGroupNums] = p;
            }
        }
        
        head = emptyHead->next;
        delete emptyHead;
        return head;
    }
};