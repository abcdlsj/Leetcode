// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) return true;
        if(s == NULL && t != NULL) return false;
        return SubTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool SubTree(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL) return true;
        if (A == NULL || B == NULL) return false;

        return A->val == B->val && SubTree(A->left, B->left) && SubTree(A->right, B->right);
    }
};
