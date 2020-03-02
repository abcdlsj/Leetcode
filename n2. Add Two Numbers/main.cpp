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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *cur = NULL;
        int pro = 0;
        while(l1 || l2) {
            int sum = pro;
            if(l1) {sum += l1->val;l1 = l1->next;}
            if(l2) {sum += l2->val;l2 = l2->next;}
            if(!cur) {
                cur = head = new ListNode(sum);
            }
            else {
                cur -> next = new ListNode(sum);
                cur = cur -> next;
            }
            if(cur -> val >= 10) {
                pro = 1;
                cur -> val = cur -> val - 10;
            }
            else pro = 0;
        }
        if (pro == 1) cur -> next = new ListNode(pro);
        return head;
    }
};
