# Symmetric Tree *
- 题目地址: [https://leetcode-cn.com/problems/symmetric-tree](https://leetcode-cn.com/problems/symmetric-tree)
- 执行时间: 0 ms
- 内存消耗: 12.3 MB
- 通过日期: 2020-05-06 00:35

## 题目内容
<p>给定一个二叉树，检查它是否是镜像对称的。</p>



<p>例如，二叉树 <code>[1,2,2,3,4,4,3]</code> 是对称的。</p>

<pre>    1
   / \
  2   2
 / \ / \
3  4 4  3
</pre>



<p>但是下面这个 <code>[1,2,2,null,3,null,3]</code> 则不是镜像对称的:</p>

<pre>    1
   / \
  2   2
   \   \
   3    3
</pre>



<p><strong>进阶：</strong></p>

<p>你可以运用递归和迭代两种方法解决这个问题吗？</p>


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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode* leftnode, TreeNode* rightnode) {
        if(leftnode == NULL && rightnode == NULL) return true;
        if(leftnode == NULL || rightnode == NULL) return false; 
        return leftnode->val == rightnode->val && isEqual(leftnode->left, rightnode->right) && isEqual(leftnode->right, rightnode->left); 
    }
};

```