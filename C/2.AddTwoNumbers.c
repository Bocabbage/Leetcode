/*
    Title:          2.AddTowNumbers.c
    Update date:    2019/08/25
    Author:         Zhuofan Zhang
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    Better C++ results in C++/2.AddTwoNumbers.cpp
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *L1 = l1, *L2 = l2, *Result = result;
    result->next = NULL;
    int S = 0;
    while(L1 != NULL && L2 != NULL)
    {
        if(L1 != l1) // The pain spot
        {
            Result->next = malloc(sizeof(struct ListNode));
            Result = Result->next;
            Result->next = NULL;
        }
        Result->val = (L1->val + L2->val + S) % 10;
        S = (L1->val + L2->val + S) / 10;
        // Point!:Set null to next.
        Result->next = NULL;
        L1 = L1->next;
        L2 = L2->next;
    }
    
    struct ListNode* L = (L1==NULL)?L2:L1;
    
    while(L != NULL)
    {
        Result->next = malloc(sizeof(struct ListNode));
        Result = Result->next;
        Result->val = (S + L->val) % 10;
        S = (L->val + S) / 10;
        L = L->next;
        Result->next = NULL;
    }
    
    if(S>0)
    {
        Result->next = malloc(sizeof(struct ListNode));
        Result->next->val = S;
        Result->next->next = NULL;
    }
    
    return result;
}