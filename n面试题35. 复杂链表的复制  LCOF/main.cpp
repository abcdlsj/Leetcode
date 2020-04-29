// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        for(Node *node = head, *copy = NULL; node != NULL; node = node->next->next) {
            copy = new Node(node->val);
            copy->next = node->next;
            node->next = copy;
        }

        for(Node *node = head; node != NULL; node = node->next->next) {
            if(node->random != NULL) {
                node->next->random = node->random->next;
            }
        }

        Node *newhead = head->next;
        for(Node *node = head, *tmp = NULL; node != NULL && node->next != NULL;) {
            tmp = node->next;
            node->next = tmp->next;
            node = tmp;
        }
        return newhead;
    }
};
