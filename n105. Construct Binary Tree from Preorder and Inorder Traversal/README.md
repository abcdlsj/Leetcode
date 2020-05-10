# Construct Binary Tree from Preorder and Inorder Traversal **
- 题目地址: [https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)
- 执行时间: 40 ms
- 内存消耗: 17.1 MB
- 通过日期: 2020-05-02 19:29

## 题目内容
<p>根据一棵树的前序遍历与中序遍历构造二叉树。</p>

<p><strong>注意:</strong><br>
你可以假设树中没有重复的元素。</p>

<p>例如，给出</p>

<pre>前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]</pre>

<p>返回如下的二叉树：</p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>


## 解法
```cpp
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

```