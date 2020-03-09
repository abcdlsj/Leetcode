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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return false;
        ListNode *fast = head -> next, *slow = head;
        while(fast != slow) {
            if(fast -> next == NULL || fast -> next -> next == NULL) return false;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return true;
    }
};
