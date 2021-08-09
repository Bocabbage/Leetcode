/*
    Title:          2.AddTowNumbers.c
    Update date:    2021/08/09
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* L1 = l1;
        ListNode* L2 = l2;
        ListNode* result = nullptr;
        ListNode* r = nullptr;
        int S = 0;
        /* Different initial situation */
        if(L1==nullptr && L2==nullptr)
            return nullptr;
        
        if(L1!=nullptr && L2!=nullptr)
        {
            result = new ListNode((L1->val + L2->val) % 10);
            S = (l1->val + l2->val) / 10;
            L1 = L1->next;
            L2 = L2->next;
            r = result;
        }
        else if(L1!=nullptr)
        {
            result = new ListNode(L1->val);
            L1 = L1->next;
            r = result;
        }
        else
        {
            result = new ListNode(L2->val);
            L2 = L2->next;
            r = result;
        }
        
        
        /* Calculate loop for different situation */
        while(L1!=nullptr && L2!=nullptr)
        {
            r->next = new ListNode((L1->val + L2->val + S) % 10);
            S = (L1->val + L2->val + S) / 10;
            r = r->next;
            L1 = L1->next;
            L2 = L2->next;
        }
        
        while(L1!=nullptr)
        {
            r->next = new ListNode((L1->val + S) % 10);
            S = (L1->val + S) / 10;
            r = r->next;
            L1 = L1->next;
        }
        
        while(L2!=nullptr)
        {
            r->next = new ListNode((L2->val + S) % 10);
            S = (L2->val + S) / 10;
            r = r->next;
            L2 = L2->next;
        }
        
        if(S>0)
            r->next = new ListNode(S);
        
        return result;
    }
};