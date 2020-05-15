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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *cur = head;
        unordered_set<int> set;
        set.insert(head->val);
        while(cur->next) {
            if(set.find(cur->next->val) != set.end()) {
                cur->next = cur->next->next;
            } else {
                set.insert(cur->next->val);
                cur = cur->next;
            }
        }
        return head;
    }
};
