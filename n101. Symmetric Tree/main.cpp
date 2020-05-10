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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode* leftnode, TreeNode* rightnode) {
        if(leftnode == NULL && rightnode == NULL) return true;
        if(leftnode == NULL || rightnode == NULL) return false; 
        return leftnode->val == rightnode->val && isEqual(leftnode->left, rightnode->right) && isEqual(leftnode->right, rightnode->left); 
    }
};
