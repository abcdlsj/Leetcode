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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, preorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int begin, int end) {
        if(begin > end) return NULL;
        TreeNode* tree = new TreeNode(preorder[root]);
        int i = begin;
        while(i < end && preorder[root] != inorder[i]) i++;
        tree->left = build(preorder, inorder, root + 1, begin, i - 1);
        tree->right = build(preorder, inorder, root + i - begin + 1, i + 1, end);
        return tree;
    }
};
