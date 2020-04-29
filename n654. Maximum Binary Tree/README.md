# Maximum Binary Tree **
- 题目地址: [https://leetcode-cn.com/problems/maximum-binary-tree](https://leetcode-cn.com/problems/maximum-binary-tree)
- 执行时间: 120 ms
- 内存消耗: 42 MB
- 通过日期: 2020-04-24 09:32

## 题目内容
<p>给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：</p>

<ol>
	<li>二叉树的根是数组中的最大元素。</li>
	<li>左子树是通过数组中最大值左边部分构造出的最大二叉树。</li>
	<li>右子树是通过数组中最大值右边部分构造出的最大二叉树。</li>
</ol>

<p>通过给定的数组构建最大二叉树，并且输出这个树的根节点。</p>



<p><strong>示例 ：</strong></p>

<pre><strong>输入：</strong>[3,2,1,6,0,5]
<strong>输出：</strong>返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li>给定的数组的大小在 [1, 1000] 之间。</li>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildhelper(nums, 0, nums.size() - 1);
    }
    TreeNode* buildhelper(vector<int> &nums, int begin, int end) {
        if(begin > end) return NULL;
        int maxnum = INT_MIN, maxpos = -1;
        for(int i = begin; i <= end; i++) {
            if(nums[i] > maxnum) {
                maxnum = nums[i];
                maxpos = i;
            }
        }
        TreeNode* node = new TreeNode(maxnum);
        node->left = buildhelper(nums, begin, maxpos - 1);
        node->right = buildhelper(nums, maxpos + 1, end);
        return node;
    }
};

```