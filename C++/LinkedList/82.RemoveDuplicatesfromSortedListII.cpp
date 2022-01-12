/*
    Title:          82.RemoveDuplicatesfromSortedListII.cpp
    Update date:    2022/01/12
    Author:         Zhuofan Zhang
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode dummy = ListNode(0, head);
        ListNode *p = &dummy, *q = head, *r = head->next;
        while(r)
        {         
            while(r && q->val == r->val)
                r = r->next;
            
            if(q->next != r)
            {
                p->next = r;
                while(q != r)
                {
                    ListNode* tmp = q;
                    q = q->next;
                    delete tmp;
                }
            }
            else if(r)
            {
                p = q;
                q = r;
                r = r->next;
            }
        }

        return dummy.next;
    }
};