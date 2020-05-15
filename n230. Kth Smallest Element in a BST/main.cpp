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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(!stack.empty() || cur) {
            while(cur) {
                stack.push(cur);
                cur = cur->left;
            }
            TreeNode *node = stack.top(); stack.pop();
            if(--k == 0) return node->val;
            if(node->right) cur = node->right;
        }
        return -1;
    }
};
