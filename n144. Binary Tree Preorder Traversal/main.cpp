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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sta;
        if(!root) return ans;
        sta.push(root);
        while(!sta.empty()) {
            TreeNode* cur = sta.top();
            sta.pop();
            ans.push_back(cur->val);
            if(cur->right) sta.push(cur->right);
            if(cur->left) sta.push(cur->left);
        }
        return ans;
    }
};
