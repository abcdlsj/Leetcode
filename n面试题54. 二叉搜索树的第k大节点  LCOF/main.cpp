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
    int ans = 0, cnt = 0;
    int kthLargest(TreeNode* root, int k) {
        inorderTraversal(root, k);
        return ans;
        
    }
    void inorderTraversal(TreeNode *root, int k) {
        stack<TreeNode*> stack;
        TreeNode *cur = root;
        while(!stack.empty() || cur != NULL) {
            while(cur != NULL) {
                stack.push(cur);
                cur = cur->right;
            }
            TreeNode *node = stack.top(); stack.pop();
            if(++cnt == k) {
                ans = node->val;
                break;
            }
            if(node->left) cur = node->left;
        }
    }
};
