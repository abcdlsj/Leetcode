# 树的子结构  LCOF **
- 题目地址: [https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof)
- 执行时间: 88 ms
- 内存消耗: 33.6 MB
- 通过日期: 2020-04-24 17:59

## 题目内容
<p>输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)</p>

<p>B是A的子结构， 即 A中有出现和B相同的结构和节点值。</p>

<p>例如:<br>
给定的树 A:</p>

<p><code>     3<br>
    / \<br>
   4   5<br>
  / \<br>
 1   2</code><br>
给定的树 B：</p>

<p><code>   4 <br>
  /<br>
 1</code><br>
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>A = [1,2,3], B = [3,1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>A = [3,4,5,1,2], B = [4,1]
<strong>输出：</strong>true</pre>

<p><strong>限制：</strong></p>

<p><code>0 <= 节点个数 <= 10000</code></p>


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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL) return false;
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool dfs(TreeNode* A, TreeNode* B) {
        if(B == NULL) return true;
        if(A == NULL) return false;
        return A->val == B->val && dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};

```