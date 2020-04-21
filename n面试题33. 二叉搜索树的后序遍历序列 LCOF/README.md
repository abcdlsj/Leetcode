# 二叉搜索树的后序遍历序列 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof)
- 执行时间: 0 ms
- 内存消耗: 7.4 MB
- 通过日期: 2020-04-19 08:03

## 题目内容
<p>输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 <code>true</code>，否则返回 <code>false</code>。假设输入的数组的任意两个数字都互不相同。</p>



<p>参考以下这颗二叉搜索树：</p>

<pre>     5
    / \
   2   6
  / \
 1   3</pre>

<p><strong>示例 1：</strong></p>

<pre><strong>输入: </strong>[1,6,3,2,5]
<strong>输出: </strong>false</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入: </strong>[1,3,2,6,5]
<strong>输出: </strong>true</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>数组长度 <= 1000</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stack;
        int prevElem = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; i--) {
            if(postorder[i] > prevElem) return false;
            while(!stack.empty() && postorder[i] < stack.top()) {
                prevElem = stack.top();
                stack.pop();
            }
            stack.push(postorder[i]);
        }
        return true;
    }
};

```