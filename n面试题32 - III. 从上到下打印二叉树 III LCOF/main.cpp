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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> queue; queue.push(root);
        int odd = 1;
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> tmp;
            while(size--) {
                TreeNode* cur = queue.front(); queue.pop();
                tmp.push_back(cur->val);
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            }
            if(odd) {
                res.push_back(tmp);
            } else {
                res.push_back(vector<int> (tmp.rbegin(), tmp.rend()));
            }
            odd = !odd;
        }
        return res;
    }
};
