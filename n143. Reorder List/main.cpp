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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next == NULL) return;
        ListNode *slow = head, *fast = head, *cur = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *insertList= slow->next;
        slow->next = NULL;
        insertList = reverse(insertList);
        while(cur && insertList) {
            ListNode *insertNode = insertList, *curNext = cur->next;
            insertList = insertList->next;
            insertNode->next = cur->next;
            cur->next = insertNode;
            cur = curNext;
        }
    }

    ListNode *reverse(ListNode *head) {
        ListNode *pre = NULL, *cur = head;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur; cur = tmp;
        }
        return pre;
    }
};
