# 二叉搜索树的第k大节点  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof)
- 执行时间: 32 ms
- 内存消耗: 24.2 MB
- 通过日期: 2020-04-24 21:30

## 题目内容
<p>给定一棵二叉搜索树，请找出其中第k大的节点。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
<strong>输出:</strong> 4</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
<strong>输出:</strong> 4</pre>



<p><strong>限制：</strong></p>

<p>1 ≤ k ≤ 二叉搜索树元素个数</p>


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
    int ans = 0, cnt = 0;
    int kthLargest(TreeNode* root, int k) {
        inorderTraversal(root, k);
        return ans;
    }
    void inorderTraversal(TreeNode *root, int k) {
        stack<TreeNode*> stack;
        TreeNode *cur = root;
        while(!stack.empty() || cur != NULL) {
            while(cur != NULL) {
                stack.push(cur);
                cur = cur->right;
            }
            TreeNode *node = stack.top(); stack.pop();
            if(++cnt == k) {
                ans = node->val;
                break;
            }
            if(node->left) cur = node->left;
        }
    }
};

```