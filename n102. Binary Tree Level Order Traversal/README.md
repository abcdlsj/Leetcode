# Binary Tree Level Order Traversal **
- 题目地址: [https://leetcode-cn.com/problems/binary-tree-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-level-order-traversal)
- 执行时间: 8 ms
- 内存消耗: 11.8 MB
- 通过日期: 2020-04-22 01:40

## 题目内容
<p>给你一个二叉树，请你返回其按 <strong>层序遍历</strong> 得到的节点值。 （即逐层地，从左到右访问所有节点）。</p>



<p><strong>示例：</strong><br>
二叉树：<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回其层次遍历结果：</p>

<pre>[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> que; que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            while (size--) {
                TreeNode* cur = que.front(); que.pop();
                tmp.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

```