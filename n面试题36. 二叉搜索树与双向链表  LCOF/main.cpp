// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *head, *pre;
    Node *treeToDoublyList(Node *root) {
        if(root == NULL) return NULL;
        head = NULL;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void dfs(Node *root) {
        if(root == NULL) return;
        dfs(root->left);
        if(head == NULL) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        dfs(root->right);
    }
};
