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
        if(head -> next == NULL || head == NULL) return head;
        
        ListNode *cur = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return cur;
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if(head == NULL) return res;
        ListNode* reverseHead = reverseList(head);
        while(reverseHead) {
            res.push_back(reverseHead -> val);
            reverseHead = reverseHead -> next;
        }
        return res;
    }
};
