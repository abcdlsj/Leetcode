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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        if(root) {
            stack.push(root);
        } else {
            return res;
        }
        while(!stack.empty()) {
            TreeNode* cur = stack.top(); stack.pop();
            res.push_back(cur->val);
            if(cur->right) stack.push(cur->right);
            if(cur->left) stack.push(cur->left);
        }
        return res;
    }
};
