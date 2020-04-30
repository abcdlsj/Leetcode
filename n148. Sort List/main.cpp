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
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
    ListNode* mergesort(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head->next->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightList = mergesort(slow->next);
        slow->next = NULL;
        ListNode* leftList = mergesort(head);
        return merge(leftList, rightList); 
    }
    ListNode* merge(ListNode* leftList, ListNode* rightList) {
        ListNode *head = new ListNode(-1), *cur = head;
        while(leftList != NULL && rightList != NULL) {
            if(leftList->val < rightList->val) {
                cur->next = leftList;
                leftList = leftList->next;
            } else {
                cur->next = rightList;
                rightList = rightList->next;
            }
            cur = cur->next;
        }
        if(leftList == NULL) cur->next = rightList;
        if(rightList == NULL) cur->next = leftList;
        return head->next;
    }
};
