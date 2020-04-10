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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> ans;
        TreeNode* cur = root;
        while(!sta.empty()||cur!=NULL) {
            while(cur!=NULL) {
                sta.push(cur);
                cur = cur->left;
            }
            TreeNode* node = sta.top();sta.pop();
            ans.push_back(node->val);
            if(node->right) cur = node->right;
        }
        return ans;
    }
};
