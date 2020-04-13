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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> sta1, sta2;
        sta1.push(root);
        while(!sta1.empty()) {
            TreeNode* cur = sta1.top();
            sta1.pop();sta2.push(cur);
            if(cur->left) sta1.push(cur->left);
            if(cur->right) sta1.push(cur->right);
         }
        while(!sta2.empty()) {
            ans.push_back(sta2.top() -> val);
            sta2.pop();
        }
        return ans;
    }
};
