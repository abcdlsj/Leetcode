# Binary Tree Preorder Traversal **
- 题目地址: [https://leetcode-cn.com/problems/binary-tree-preorder-traversal](https://leetcode-cn.com/problems/binary-tree-preorder-traversal)
- 执行时间: 0 ms
- 内存消耗: 9.9 MB
- 通过日期: 2020-03-17 14:55

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sta;
        if(!root) return ans;
        sta.push(root);
        while(!sta.empty()) {
            TreeNode* cur = sta.top();
            sta.pop();
            ans.push_back(cur->val);
            if(cur->right) sta.push(cur->right);
            if(cur->left) sta.push(cur->left);
        }
        return ans;
    }
};

```