/*
    Title:          206.ReverseLinkedList.cpp
    Update date:    2021/12/02
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

/* Recursion version */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* tmp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tmp;
    }
};

/* Iteration version */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
        
//         /* in-place */
//         ListNode* p = head;
//         ListNode* q = p->next;

//         while(q != NULL)
//         {
//             ListNode* tmp = q->next;
//             q->next = p;
//             p = q;
//             q = tmp;
//         }

//         head->next = NULL;
//         return p;
//     }
// };