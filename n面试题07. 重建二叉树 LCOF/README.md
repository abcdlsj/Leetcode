# 重建二叉树 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof)
- 执行时间: 32 ms
- 内存消耗: 23.3 MB
- 通过日期: 2020-03-05 22:06

## 题目内容
<p>输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。</p>



<p>例如，给出</p>

<pre>前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]</pre>

<p>返回如下的二叉树：</p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= 节点个数 <= 5000</code></p>



<p><strong>注意</strong>：本题与主站 105 题重复：<a href="https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/">https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/</a></p>


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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int begin, int end) {
        if(begin > end) return NULL;
        TreeNode* tree = new TreeNode(preorder[root]);
        int i = begin;
        while(i < end && preorder[root] != inorder[i]) i++;
        tree -> left = build(preorder, inorder, root + 1, begin, i - 1);
        tree -> right = build(preorder, inorder, root + 1 + i - begin, i + 1, end);
        return tree;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};

```