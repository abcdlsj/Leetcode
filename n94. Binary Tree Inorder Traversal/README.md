# Binary Tree Inorder Traversal **
- 题目地址: [https://leetcode-cn.com/problems/binary-tree-inorder-traversal](https://leetcode-cn.com/problems/binary-tree-inorder-traversal)
- 执行时间: 0 ms
- 内存消耗: 7.3 MB
- 通过日期: 2020-05-05 21:10

## 题目内容
<p>给定一个二叉树，返回它的<em>中序 </em>遍历。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,null,2,3]
   1
    \
     2
    /
   3

<strong>输出:</strong> [1,3,2]</pre>

<p><strong>进阶:</strong> 递归算法很简单，你可以通过迭代算法完成吗？</p>


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(!stack.empty() || cur) {
            while(cur) {
                stack.push(cur);
                cur = cur->left;
            }
            TreeNode *node = stack.top(); stack.pop();
            res.push_back(node->val);
            if(node->right) cur = node->right;
        }
        return res;
    }
};

```