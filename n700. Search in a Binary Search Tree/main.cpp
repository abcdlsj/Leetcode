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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root && root->val == val) return root;
        TreeNode* node_left = searchBST(root->left, val);
        TreeNode* node_right = searchBST(root->right, val);
        if(node_left != NULL) return node_left;
        if(node_right != NULL) return node_right;
        return NULL;
    }
};
