# First Common Ancestor LCCI **
- 题目地址: [https://leetcode-cn.com/problems/first-common-ancestor-lcci](https://leetcode-cn.com/problems/first-common-ancestor-lcci)
- 执行时间: 24 ms
- 内存消耗: 14.5 MB
- 通过日期: 2020-04-12 16:32

## 题目内容
<p>设计并实现一个算法，找出二叉树中某两个节点的第一个共同祖先。不得将其他的节点存储在另外的数据结构中。注意：这不一定是二叉搜索树。</p><p>例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]</p><pre>    3<br>   / \<br>  5   1<br> / \ / \<br>6  2 0  8<br>  / \<br> 7   4<br></pre><strong>示例 1:</strong><pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1<br><strong>输入:</strong> 3<br><strong>解释:</strong> 节点 5 和节点 1 的最近公共祖先是节点 3。</pre><strong>示例 2:</strong><pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4<br><strong>输出:</strong> 5<br><strong>解释:</strong> 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。</pre><strong>说明:</strong><pre>所有节点的值都是唯一的。<br>p、q 为不同节点且均存在于给定的二叉树中。</pre>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* node_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* node_right = lowestCommonAncestor(root->right, p, q);
        if(node_left && node_right) return root;
        if(node_left == NULL && node_right) return node_right;
        else return node_left;
    }
};

```