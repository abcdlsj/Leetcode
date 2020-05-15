# Subtree of Another Tree *
- 题目地址: [https://leetcode-cn.com/problems/subtree-of-another-tree](https://leetcode-cn.com/problems/subtree-of-another-tree)
- 执行时间: 44 ms
- 内存消耗: 29.2 MB
- 通过日期: 2020-05-07 10:16

## 题目内容
<p>给定两个非空二叉树 <strong>s</strong> 和 <strong>t</strong>，检验 <strong>s</strong> 中是否包含和 <strong>t</strong> 具有相同结构和节点值的子树。<strong>s</strong> 的一个子树包括 <strong>s</strong> 的一个节点和这个节点的所有子孙。<strong>s</strong> 也可以看做它自身的一棵子树。</p>

<p><strong>示例 1:</strong><br />
给定的树 s:</p>

<pre>
     3
    / \
   4   5
  / \
 1   2
</pre>

<p>给定的树 t：</p>

<pre>
   4 
  / \
 1   2
</pre>

<p>返回 <strong>true</strong>，因为 t 与 s 的一个子树拥有相同的结构和节点值。</p>

<p><strong>示例 2:</strong><br />
给定的树 s：</p>

<pre>
     3
    / \
   4   5
  / \
 1   2
    /
   0
</pre>

<p>给定的树 t：</p>

<pre>
   4
  / \
 1   2
</pre>

<p>返回 <strong>false</strong>。</p>


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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) return true;
        if(s == NULL && t != NULL) return false;
        return SubTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool SubTree(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL) return true;
        if (A == NULL || B == NULL) return false;

        return A->val == B->val && SubTree(A->left, B->left) && SubTree(A->right, B->right);
    }
};

```