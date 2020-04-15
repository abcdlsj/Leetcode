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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(getdepth(root->left) - getdepth(root->right)) <= 1) {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }
    int getdepth(TreeNode* root) {
        return root == NULL ? 0 : max(getdepth(root->left), getdepth(root->right)) + 1;
    }
};
