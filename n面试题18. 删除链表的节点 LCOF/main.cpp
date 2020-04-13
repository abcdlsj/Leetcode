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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *cur = head, *pre = NULL;
        if(cur == NULL) return head;
        if(cur->val == val) return head->next;
        while(cur && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
