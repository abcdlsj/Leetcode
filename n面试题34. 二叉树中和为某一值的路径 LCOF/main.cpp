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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        getpath(root, path, sum);
        return res;
    }
    void getpath(TreeNode* root, vector<int> &path, int sum) {
        if(root == NULL) return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL & accumulate(path.begin(), path.end(), 0) == sum) res.push_back(path);
        getpath(root->left, path, sum);
        getpath(root->right, path, sum);
        path.pop_back();
    }
};
