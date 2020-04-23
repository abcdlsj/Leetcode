# 从上到下打印二叉树 III LCOF **
- 题目地址: [https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof)
- 执行时间: 12 ms
- 内存消耗: 12.8 MB
- 通过日期: 2020-04-22 09:16

## 题目内容
<p>请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。</p>



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
  [20,9],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> queue; queue.push(root);
        int odd = 1;
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> tmp;
            while(size--) {
                TreeNode* cur = queue.front(); queue.pop();
                tmp.push_back(cur->val);
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            }
            if(odd) {
                res.push_back(tmp);
            } else {
                res.push_back(vector<int> (tmp.rbegin(), tmp.rend()));
            }
            odd = !odd;
        }
        return res;
    }
};

```