// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

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
    ListNode* mergeTwoLists(ListNode* i1, ListNode* i2) {;
        ListNode *i3 = new ListNode, *cur = i3;
        while(i1 && i2) {
            if(i1->val <= i2->val) {
                cur->next = i1;
                i1 = i1->next;
            } else {
                cur->next = i2;
                i2 = i2->next;
            }
            cur = cur->next;
        }
        if(i1 == nullptr) cur->next = i2;
        if(i2 == nullptr) cur->next = i1;
        return i3->next;
    }
};
