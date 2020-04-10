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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *fast= head, *slow = head;
        while(fast != NULL && fast->next !=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(fast == slow) fast = head;
        else return NULL;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
