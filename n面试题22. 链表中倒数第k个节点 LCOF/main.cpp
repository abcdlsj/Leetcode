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
    ListNode* getKthFromEnd(ListNode* pListHead, int k) {
        if(pListHead == NULL || k == 0) return NULL;
        ListNode *slow = pListHead, *fast = pListHead;
        for(int i = 1; i < k && fast; i++) fast = fast->next;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast == NULL ? NULL : slow;
    }
};
