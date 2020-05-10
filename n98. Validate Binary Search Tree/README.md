# Validate Binary Search Tree **
- 题目地址: [https://leetcode-cn.com/problems/validate-binary-search-tree](https://leetcode-cn.com/problems/validate-binary-search-tree)
- 执行时间: 16 ms
- 内存消耗: 18.5 MB
- 通过日期: 2020-05-05 21:41

## 题目内容
<p>给定一个二叉树，判断其是否是一个有效的二叉搜索树。</p>

<p>假设一个二叉搜索树具有如下特征：</p>

<ul>
	<li>节点的左子树只包含<strong>小于</strong>当前节点的数。</li>
	<li>节点的右子树只包含<strong>大于</strong>当前节点的数。</li>
	<li>所有左子树和右子树自身必须也是二叉搜索树。</li>
</ul>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
    2
   / \
  1   3
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:
</strong>    5
   / \
  1   4
     / \
    3   6
<strong>输出:</strong> false
<strong>解释:</strong> 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
</pre>


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
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(!stack.empty() || cur) {
            while(cur) {
                stack.push(cur);
                cur = cur->left;
            }
            TreeNode* node = stack.top(); stack.pop();
            if(pre >= node->val) return false;
            pre = node->val;
            if(node->right) cur = node->right;
        }
        return true;
        // if(!root) return true;
        // if(!isValidBST(root->left)) return false;
        // if(pre >= root->val) return false;
        // pre = root->val;
        // return isValidBST(root->right);
    }
};

```