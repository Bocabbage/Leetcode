/*
    Title:          142.LinkedListCycleII.cpp
    Update date:    2021/12/02
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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        if(head->next->next==head)
            return head;
        else if(head->next->next==NULL)
            return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        if(fast==slow)
        // 可证明：相遇点距离起点位置距离 = 环长度
        {
            fast=head;
            while(fast->next!=slow->next)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return fast->next;
        }
        return NULL;
    }
};