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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *node = new ListNode(0);
    ListNode *curnode = node;
    int tmp = 0;
    while (l1 || l2 || tmp) {
      tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + tmp;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
      node->next = new ListNode(tmp % 10);
      tmp /= 10;
      node = node->next;
    }
    return curnode->next;
  }
};
