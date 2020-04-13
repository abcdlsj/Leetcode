# Binary Tree Preorder Traversal **
- 题目地址: [https://leetcode-cn.com/problems/binary-tree-preorder-traversal](https://leetcode-cn.com/problems/binary-tree-preorder-traversal)
- 执行时间: 4 ms
- 内存消耗: 8.7 MB
- 通过日期: 2020-04-12 09:37

## 题目内容
<p>给定一个二叉树，返回它的 <em>前序 </em>遍历。</p>

<p> <strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,null,2,3]  
   1
    \
     2
    /
   3 

<strong>输出:</strong> [1,2,3]
</pre>

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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        if(root) {
            stack.push(root);
        } else {
            return res;
        }
        while(!stack.empty()) {
            TreeNode* cur = stack.top(); stack.pop();
            res.push_back(cur->val);
            if(cur->right) stack.push(cur->right);
            if(cur->left) stack.push(cur->left);
        }
        return res;
    }
};

```