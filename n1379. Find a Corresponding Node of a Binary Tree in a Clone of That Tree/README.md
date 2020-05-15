# Find a Corresponding Node of a Binary Tree in a Clone of That Tree **
- 题目地址: [https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree](https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree)
- 执行时间: 880 ms
- 内存消耗: 164.5 MB
- 通过日期: 2020-05-15 08:36

## 题目内容
<p>给你两棵二叉树，原始树 <code>original</code> 和克隆树 <code>cloned</code>，以及一个位于原始树 <code>original</code> 中的目标节点 <code>target</code>。</p>

<p>其中，克隆树 <code>cloned</code> 是原始树 <code>original</code> 的一个<strong> 副本 </strong>。</p>

<p>请找出在树 <code>cloned</code> 中，与 <code>target</code> <strong>相同 </strong>的节点，并返回对该节点的引用（在 C/C++ 等有指针的语言中返回 节点指针，其他语言返回节点本身）。</p>



<p><strong>注意：</strong></p>

<ol>
	<li>你 <strong>不能</strong> 对两棵二叉树，以及 <code>target</code> 节点进行更改。</li>
	<li><strong>只能</strong> 返回对克隆树 <code>cloned</code> 中已有的节点的引用。</li>
</ol>

<ul>
</ul>

<p><strong>进阶：</strong>如果树中允许出现值相同的节点，你将如何解答？</p>



<ul>
</ul>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e1.png" style="height: 426px; width: 544px;"></p>

<pre><strong>输入:</strong> tree = [7,4,3,null,null,6,19], target = 3
<strong>输出:</strong> 3
<strong>解释:</strong> 上图画出了树 original 和 cloned。target 节点在树 original 中，用绿色标记。答案是树 cloned 中的黄颜色的节点（其他示例类似）。</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e2.png" style="height: 159px; width: 221px;"></p>

<pre><strong>输入:</strong> tree = [7], target =  7
<strong>输出:</strong> 7
</pre>

<p><strong>示例 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e3.png" style="height: 486px; width: 459px;"></p>

<pre><strong>输入:</strong> tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
<strong>输出:</strong> 4
</pre>

<p><strong>示例 4:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e4.png" style="height: 239px; width: 555px;"></p>

<pre><strong>输入:</strong> tree = [1,2,3,4,5,6,7,8,9,10], target = 5
<strong>输出:</strong> 5
</pre>

<p><strong>示例 5:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e5.png" style="height: 345px; width: 427px;"></p>

<pre><strong>输入:</strong> tree = [1,2,null,3], target = 2
<strong>输出:</strong> 2</pre>



<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量范围为 <code>[1, 10^4]</code> 。</li>
	<li>同一棵树中，没有值相同的节点。</li>
	<li><code>target</code> 节点是树 <code>original</code> 中的一个节点，并且不会是 <code>null</code> 。</li>
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(original == target) return cloned;
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        TreeNode *right = getTargetCopy(original->right, cloned->right, target);
        return left ? left : right;
    }
};

```