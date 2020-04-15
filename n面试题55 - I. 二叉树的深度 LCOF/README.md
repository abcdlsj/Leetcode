# 二叉树的深度 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof)
- 执行时间: 12 ms
- 内存消耗: 19.1 MB
- 通过日期: 2020-04-14 12:08

## 题目内容
<p>输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。</p>

<p>例如：</p>

<p>给定二叉树 <code>[3,9,20,null,null,15,7]</code>，</p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>

<p>返回它的最大深度 3 。</p>



<p><strong>提示：</strong></p>

<ol>
	<li><code>节点总数 <= 10000</code></li>
</ol>

<p>注意：本题与主站 104 题相同：<a href="https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/">https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/</a></p>


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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

```