# Search in a Binary Search Tree *
- 题目地址: [https://leetcode-cn.com/problems/search-in-a-binary-search-tree](https://leetcode-cn.com/problems/search-in-a-binary-search-tree)
- 执行时间: 72 ms
- 内存消耗: 34.7 MB
- 通过日期: 2020-04-12 10:15

## 题目内容
<p>给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。</p>

<p>例如，</p>

<pre>
给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
</pre>

<p>你应该返回如下子树:</p>

<pre>
      2     
     / \   
    1   3
</pre>

<p>在上述示例中，如果要找的值是 <code>5</code>，但因为没有节点值为 <code>5</code>，我们应该返回 <code>NULL</code>。</p>


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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root && root->val == val) return root;
        TreeNode* node_left = searchBST(root->left, val);
        TreeNode* node_right = searchBST(root->right, val);
        if(node_left != NULL) return node_left;
        if(node_right != NULL) return node_right;
        return NULL;
    }
};

```