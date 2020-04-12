# Rotate String *
- 题目地址: [https://leetcode-cn.com/problems/rotate-string](https://leetcode-cn.com/problems/rotate-string)
- 执行时间: 0 ms
- 内存消耗: 6.1 MB
- 通过日期: 2020-03-30 17:47

## 题目内容
<p>给定两个字符串, <code>A</code> 和 <code>B</code>。</p>

<p><code>A</code> 的旋转操作就是将 <code>A</code> 最左边的字符移动到最右边。 例如, 若 <code>A = 'abcde'</code>，在移动一次之后结果就是<code>'bcdea'</code> 。如果在若干次旋转操作之后，<code>A</code> 能变成<code>B</code>，那么返回<code>True</code>。</p>

<pre>
<strong>示例 1:</strong>
<strong>输入:</strong> A = 'abcde', B = 'cdeab'
<strong>输出:</strong> true

<strong>示例 2:</strong>
<strong>输入:</strong> A = 'abcde', B = 'abced'
<strong>输出:</strong> false</pre>

<p><strong>注意：</strong></p>

<ul>
	<li><code>A</code> 和 <code>B</code> 长度不超过 <code>100</code>。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.length() == B.length() && (A + A).find(B) != -1;
    }
};

```