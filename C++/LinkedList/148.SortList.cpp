/*
    Title:          148.SortList.cpp
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
    void merge(
        vector<int> &tmp_save,
        ListNode *p,
        ListNode *pend,
        ListNode *q,
        ListNode *qend
    )
    {
        ListNode *pp = p;
        ListNode *qq = q;

        ListNode *pstop = pend ? pend->next : nullptr;
        ListNode *qstop = qend ? qend->next : nullptr;

        int nums = 0;
        while(pp != pstop && qq != qstop)
        {
            if(pp->val <= qq->val)
            {
                tmp_save[nums] = pp->val;
                pp = pp->next;
            }
            else
            {
                tmp_save[nums] = qq->val;
                qq = qq->next;
            }
            nums++;
        }

        while(pp != pstop)
        {
            tmp_save[nums] = pp->val;
            pp = pp->next;
            nums++;
        }

        while(qq != qstop)
        {
            tmp_save[nums] = qq->val;
            qq = qq->next;
            nums++;
        }

        pp = p;
        for(int i = 0; i< nums; ++i)
        {
            pp->val = tmp_save[i];
            pp = pp->next;
        }
    }

    ListNode* sortList(ListNode* head) {

        if(!head || !(head->next))
            return head;

        // Merge sort: bottom-to-top version
        int list_sz = 0;
        ListNode *tmp = head;
        while(tmp)
        {
            tmp = tmp->next;
            list_sz++;
        }

        int merge_max = 2;
        while(merge_max < list_sz)merge_max = merge_max << 1;

        vector<int> tmp_save(list_sz, 0);

        int mid_sz = 1, sz = 2;
        for(; sz <= merge_max; sz += sz)
        {

            ListNode *lo = head;
            ListNode *hi = nullptr;
            ListNode *mid = nullptr;
            for(int i = 0; i < list_sz; i += sz)
            {
                hi = lo;
                mid = lo;
                for(int j = 1; j < sz; ++j)
                {
                    if(!(hi->next))
                        break;
                    if(j == mid_sz)
                        mid = hi;
                    hi = hi->next;
                }

                merge(tmp_save, lo, mid, mid->next, hi);
                lo = hi->next;
            }

            mid_sz = sz;
        }

        return head;
    }
};