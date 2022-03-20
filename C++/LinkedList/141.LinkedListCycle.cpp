/*
    Title:          141.LinkedListCycle.cpp
    Update date:    2021/12/02
    Author:         Zhuofan Zhang
*/
class Solution {
public:

bool hasCycle(ListNode *head) {
    
    ListNode *fast = head ;
    ListNode *slow = head ;
    
    if(!head) return false ;
    
    while(fast && fast->next)
    {
        slow = slow->next ;
        fast = fast->next->next ;
        if(slow == fast) return true ;
    }
    
    return false ;
    
}
};