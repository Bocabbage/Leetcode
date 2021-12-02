/*
    Title:          234.PalindromeLinkedList.cpp
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> first_half;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next)
        {
            first_half.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(fast)
            // list.size() &0x1
            slow = slow->next;
        
        while(!first_half.empty())
        {
            if(slow->val != first_half.top())
                return false;
            slow = slow->next;
            first_half.pop();
        }
        
        return true;
    }
};