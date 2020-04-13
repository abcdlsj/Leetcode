# 对称的二叉树  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof)
- 执行时间: 12 ms
- 内存消耗: 16.2 MB
- 通过日期: 2020-04-13 14:22

## 题目内容
<p>请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。</p>

<p>例如，二叉树 [1,2,2,3,4,4,3] 是对称的。</p>

<p><code>    1<br>
   / \<br>
  2   2<br>
 / \ / \<br>
3  4 4  3</code><br>
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:</p>

<p><code>    1<br>
   / \<br>
  2   2<br>
   \   \<br>
   3    3</code></p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>root = [1,2,2,3,4,4,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>root = [1,2,2,null,3,null,3]
<strong>输出：</strong>false</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= 节点个数 <= 1000</code></p>

<p>注意：本题与主站 101 题相同：<a href="https://leetcode-cn.com/problems/symmetric-tree/">https://leetcode-cn.com/problems/symmetric-tree/</a></p>


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
        return judge(root->left, root->right); 
    }
    bool judge(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;
        return judge(left->left, right->right) && judge(left->right, right->left);
    }
};

```