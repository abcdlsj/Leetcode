# 平衡二叉树 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof)
- 执行时间: 16 ms
- 内存消耗: 21.6 MB
- 通过日期: 2020-04-14 12:20

## 题目内容
<p>输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。</p>



<p><strong>示例 1:</strong></p>

<p>给定二叉树 <code>[3,9,20,null,null,15,7]</code></p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>

<p>返回 <code>true</code> 。<br>
<br>
<strong>示例 2:</strong></p>

<p>给定二叉树 <code>[1,2,2,3,3,null,null,4,4]</code></p>

<pre>       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
</pre>

<p>返回 <code>false</code> 。</p>



<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= 树的结点个数 <= 10000</code></li>
</ul>

<p>注意：本题与主站 110 题相同：<a href="https://leetcode-cn.com/problems/balanced-binary-tree/">https://leetcode-cn.com/problems/balanced-binary-tree/</a></p>




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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(depth(root->left) - depth(root->right)) <= 1) {
            return isBalanced(root->left) && isBalanced(root->right);  
        }
        return false;
    }
    int depth(TreeNode* root) {
        return root == NULL ? 0 : max(depth(root->left), depth(root->right)) + 1;
    }
};

```