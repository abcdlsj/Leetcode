# 二叉树中和为某一值的路径 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof)
- 执行时间: 20 ms
- 内存消耗: 20.2 MB
- 通过日期: 2020-04-18 20:06

## 题目内容
<p>输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。</p>



<p><strong>示例:</strong><br>
给定如下二叉树，以及目标和 <code>sum = 22</code>，</p>

<pre>              <strong>5</strong>
             / \
            <strong>4</strong>   <strong>8</strong>
           /   / \
          <strong>11</strong>  13  <strong>4</strong>
         /  \    / \
        7    <strong>2</strong>  <strong>5</strong>   1
</pre>

<p>返回:</p>

<pre>[
   [5,4,11,2],
   [5,8,4,5]
]
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>节点总数 <= 10000</code></li>
</ol>

<p>注意：本题与主站 113 题相同：<a href="https://leetcode-cn.com/problems/path-sum-ii/">https://leetcode-cn.com/problems/path-sum-ii/</a></p>


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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        getpath(root, path, sum);
        return res;
    }
    void getpath(TreeNode* root, vector<int> &path, int sum) {
        if(root == NULL) return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL & accumulate(path.begin(), path.end(), 0) == sum) res.push_back(path);
        getpath(root->left, path, sum);
        getpath(root->right, path, sum);
        path.pop_back();
    }
};

```