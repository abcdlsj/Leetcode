# Binary Tree Postorder Traversal ***
- 题目地址: [https://leetcode-cn.com/problems/binary-tree-postorder-traversal](https://leetcode-cn.com/problems/binary-tree-postorder-traversal)
- 执行时间: 4 ms
- 内存消耗: 10.3 MB
- 通过日期: 2020-03-17 14:54

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
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> sta1, sta2;
        sta1.push(root);
        while(!sta1.empty()) {
            TreeNode* cur = sta1.top();
            sta1.pop();sta2.push(cur);
            if(cur->left) sta1.push(cur->left);
            if(cur->right) sta1.push(cur->right);
         }
        while(!sta2.empty()) {
            ans.push_back(sta2.top() -> val);
            sta2.pop();
        }
        return ans;
    }
};

```