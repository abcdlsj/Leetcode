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
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int pRootIdx, int beginIdx, int endIdx) {
        if(beginIdx > endIdx) return NULL;
        int iRootIdx = beginIdx;
        while(iRootIdx < endIdx && inorder[iRootIdx] != preorder[pRootIdx]) iRootIdx++;
        TreeNode *tree = new TreeNode(preorder[pRootIdx]);
        tree->left = build(preorder, inorder, pRootIdx + 1, beginIdx, iRootIdx - 1);
        tree->right = build(preorder, inorder, pRootIdx + iRootIdx - beginIdx + 1, iRootIdx + 1, endIdx);
        return tree;
    }
};
