/*
    Title:          21.MergeTowSortedList.cpp
    Update date:    2019/11/08
    Author:         Zhuofan Zhang
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        /* Method1:(98.96%,55.74%) */
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        int tmp_val;
        auto *p = l1, *q = l2;
        if(l1->val < l2->val)
        {
            tmp_val = l1->val;
            p = l1->next;
        }
        else
        {
            tmp_val = l2->val;
            q = l2->next;
        }
        ListNode* res = new ListNode(tmp_val);
        auto *r = res;
        
        while(p != NULL && q !=NULL)
        {
            if(p->val < q->val)
            {
                r->next = new ListNode(p->val);
                p = p->next;
            }
            else
            {
                r->next = new ListNode(q->val);
                q = q->next;
            }
            r = r->next;
        }
        
        if(p == NULL && q != NULL)
            p = q;
        while( p!=NULL )
        {
            r->next = new ListNode(p->val);
            r = r->next;
            p = p->next;
        }
        
        return res;
    }
};