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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;  
        ListNode *oddHead = head, *rtOdd = head, *evenHead = head->next, *rtEven = head->next;
        head = head->next->next;
        int index = 3;
        while(head != NULL) {
            if(index % 2 == 0) {
                evenHead->next = head;
                evenHead = evenHead->next;
            } else {
                oddHead->next = head;
                oddHead = oddHead->next;
            }
            index++;
            head = head->next;
        }
        evenHead->next = NULL, oddHead->next = rtEven;
        return rtOdd;
    }
};
