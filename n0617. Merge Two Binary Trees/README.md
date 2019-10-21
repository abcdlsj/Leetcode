# Merge Two Binary Trees *
- 题目地址: [https://leetcode-cn.com/problems/merge-two-binary-trees](https://leetcode-cn.com/problems/merge-two-binary-trees)
- 执行时间: 48 ms 
- 内存消耗: 13.4 MB
- 通过日期: 2019-09-21 16:24

## 题目内容
<p>给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。</p>

<p>你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则<strong>不为 </strong>NULL 的节点将直接作为新二叉树的节点。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
<strong>输出:</strong> 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
</pre>

<p><strong>注意:</strong> 合并必须从两个树的根节点开始。</p>


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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr&&t2==nullptr) return nullptr;
        if(t1==nullptr&&t2) return t2;
        if(t2==nullptr&&t1) return t1;
        else {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left,t2->left);
            t1->right = mergeTrees(t1->right,t2->right);
            return t1;
        }
        return t1;
     }
};

```