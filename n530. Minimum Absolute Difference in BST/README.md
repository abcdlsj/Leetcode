# Minimum Absolute Difference in BST *
- 题目地址: [https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst)
- 执行时间: 36 ms
- 内存消耗: 25.4 MB
- 通过日期: 2020-05-06 00:42

## 题目内容
<p>给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>

   1
    \
     3
    /
   2

<strong>输出：</strong>
1

<strong>解释：
</strong>最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li>树中至少有 2 个节点。</li>
	<li>本题与 783 <a href="https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/">https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/</a> 相同</li>
</ul>


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
    int getMinimumDifference(TreeNode* root) {
        int minSub = INT_MAX, pre;
        stack<TreeNode*> stack;
        TreeNode *cur = root;
        while(!stack.empty() || cur) {
            while(cur) {
                stack.push(cur);
                cur = cur->left;
            }
            TreeNode *node = stack.top(); stack.pop();
            minSub = min(abs(node->val - pre), minSub);
            pre = node->val;
            if(node->right) cur = node->right;
        }
        return minSub;
    }
};

```