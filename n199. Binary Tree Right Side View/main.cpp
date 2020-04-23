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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> queue; queue.push(root);
        while(!queue.empty()) {
            int size = queue.size();
            res.push_back(queue.front()->val);
            while(size--) {
                TreeNode* cur = queue.front(); queue.pop();
                if(cur->right) queue.push(cur->right);
                if(cur->left) queue.push(cur->left);
            }
        }
        return res;
    }
};
