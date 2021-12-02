/*
    Title:          160.IntersectionofTwoLinkedList.cpp
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
      // 若存在交集点，两指针会提前相遇
      // 否则，a与b经过路程都为len(a) + len(b)，到达空指针结束
      a = a ? a->next : headB;
      b = b ? b->next : headA;
    }
    
    return a;
  }
};