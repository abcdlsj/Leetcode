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
    int getMinimumDifference(TreeNode* root) {
        int minSub = INT_MAX, pre;
        stack<TreeNode*> stack;
        TreeNode *cur = root;
        while(!stack.empty() || cur) {
            while(cur) {
                stack.push(cur);
                cur = cur->left;
            }
            TreeNode *node = stack.top(); stack.pop();
            minSub = min(abs(node->val - pre), minSub);
            pre = node->val;
            if(node->right) cur = node->right;
        }
        return minSub;
    }
};
