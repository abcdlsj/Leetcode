# Convert Sorted Array to Binary Search Tree *
- 题目地址: [https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree)
- 执行时间: 20 ms
- 内存消耗: 22.7 MB
- 通过日期: 2020-02-24 11:27

## 题目内容
<p>将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。</p>

<p>本题中，一个高度平衡二叉树是指一个二叉树<em>每个节点 </em>的左右两个子树的高度差的绝对值不超过 1。</p>

<p><strong>示例:</strong></p>

<pre>给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* dfs(vector<int> &nums,int left,int right){
        if(left>=right) return NULL;
        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = dfs(nums,left,mid);
        root -> right = dfs(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return dfs(nums,0,len);
    }
};

```