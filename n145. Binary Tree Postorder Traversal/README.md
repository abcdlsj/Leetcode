# Binary Tree Postorder Traversal ***
- 题目地址: [https://leetcode-cn.com/problems/binary-tree-postorder-traversal](https://leetcode-cn.com/problems/binary-tree-postorder-traversal)
- 执行时间: 0 ms
- 内存消耗: 8.6 MB
- 通过日期: 2020-05-02 13:05

## 题目内容
<p>给定一个二叉树，返回它的 <em>后序 </em>遍历。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,null,2,3]  
   1
    \
     2
    /
   3 

<strong>输出:</strong> [3,2,1]</pre>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack1, stack2;
        if(root) {
            stack1.push(root);
        } else {
            return res;
        }
        while(!stack1.empty()) {
            TreeNode* cur = stack1.top(); stack1.pop();
            stack2.push(cur);
            if(cur->left) stack1.push(cur->left);
            if(cur->right) stack1.push(cur->right);
        }
        while(!stack2.empty()) {
            res.push_back(stack2.top()->val);
            stack2.pop();
        }
        return res;
    }
};

```