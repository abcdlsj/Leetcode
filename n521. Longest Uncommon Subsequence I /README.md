# Longest Uncommon Subsequence I  *
- 题目地址: [https://leetcode-cn.com/problems/longest-uncommon-subsequence-i](https://leetcode-cn.com/problems/longest-uncommon-subsequence-i)
- 执行时间: 8 ms
- 内存消耗: 8.3 MB
- 通过日期: 2019-08-12 15:40

## 题目内容
<p>给你两个字符串，请你从这两个字符串中找出最长的特殊序列。</p>

<p>「最长特殊序列」定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。</p>

<p><strong>子序列</strong> 可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。</p>

<p>输入为两个字符串，输出最长特殊序列的长度。如果不存在，则返回 -1。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> "aba", "cdc"
<strong>输出:</strong> 3
<strong>解释:</strong> 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = "aaa", b = "bbb"
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>a = "aaa", b = "aaa"
<strong>输出：</strong>-1
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li>两个字符串长度均处于区间 <code>[1 - 100]</code> 。</li>
	<li>字符串中的字符仅含有 <code>'a'~'z'</code> 。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

#include <cstring>
#include <cmath>
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)
            return -1;
        else 
            return max(a.size(),b.size());
    }
};

```