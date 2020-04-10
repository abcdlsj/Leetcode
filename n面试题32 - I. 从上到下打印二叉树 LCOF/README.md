# 从上到下打印二叉树 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof)
- 执行时间: 8 ms
- 内存消耗: 12.4 MB
- 通过日期: 2020-04-10 09:40

## 题目内容
<p>从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。</p>



<p>例如:<br>
给定二叉树: <code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回：</p>

<pre>[3,9,20,15,7]
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>节点总数 <= 1000</code></li>
</ol>


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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root) {
            que.push(root);
        } else {
            return res;
        }
        while(!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            res.push_back(cur->val);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        return res;
    }
};

```