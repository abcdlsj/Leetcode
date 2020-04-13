# 二叉树的镜像  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof)
- 执行时间: 0 ms
- 内存消耗: 9.2 MB
- 通过日期: 2020-04-13 10:57

## 题目内容
<p>请完成一个函数，输入一个二叉树，该函数输出它的镜像。</p>

<p>例如输入：</p>

<p><code>     4<br>
   /   \<br>
  2     7<br>
 / \   / \<br>
1   3 6   9</code><br>
镜像输出：</p>

<p><code>     4<br>
   /   \<br>
  7     2<br>
 / \   / \<br>
9   6 3   1</code></p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>root = [4,2,7,1,3,6,9]
<strong>输出：</strong>[4,7,2,9,6,3,1]
</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= 节点个数 <= 1000</code></p>

<p>注意：本题与主站 226 题相同：<a href="https://leetcode-cn.com/problems/invert-binary-tree/">https://leetcode-cn.com/problems/invert-binary-tree/</a></p>


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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode *tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};

```