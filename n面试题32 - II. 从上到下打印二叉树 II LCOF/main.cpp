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
        if(root == NULL) return res;
        queue<TreeNode*> queue; queue.push(root);
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> path;
            while(size--) {
                TreeNode *cur = queue.front(); queue.pop();
                path.push_back(cur->val);
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            }
            res.push_back(path);
        }
        return res;
    }
};
