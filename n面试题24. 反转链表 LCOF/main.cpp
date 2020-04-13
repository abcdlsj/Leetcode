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
    ListNode* reverseList(ListNode* head) {
        // ListNode *cur = head, *pre = NULL, *tmp;
        // while(cur != NULL) {
        //     tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        // }
        // return pre;
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *cur = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;

        return cur;
    }
};
