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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        if(fast == NULL) return head;
        while(k >= 1) {
            fast = fast->next;
            k--;
        } 
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
