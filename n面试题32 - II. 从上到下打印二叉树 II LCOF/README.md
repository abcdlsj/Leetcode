# 从上到下打印二叉树 II LCOF *
- 题目地址: [https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof)
- 执行时间: 12 ms
- 内存消耗: 12.6 MB
- 通过日期: 2020-04-13 14:51

## 题目内容
<p>从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。</p>



<p>例如:<br>
给定二叉树: <code>[3,9,20,null,null,15,7]</code>,</p>

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



<p><strong>提示：</strong></p>

<ol>
	<li><code>节点总数 <= 1000</code></li>
</ol>

<p>注意：本题与主站 102 题相同：<a href="https://leetcode-cn.com/problems/binary-tree-level-order-traversal/">https://leetcode-cn.com/problems/binary-tree-level-order-traversal/</a></p>


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
        if(root == NULL) return res;
        queue<TreeNode*> queue; queue.push(root);
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> path;
            while(size--) {
                TreeNode *cur = queue.front(); queue.pop();
                path.push_back(cur->val);
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            }
            res.push_back(path);
        }
        return res;
    }
};

```