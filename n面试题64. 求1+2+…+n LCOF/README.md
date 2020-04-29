# 求1+2+…+n LCOF **
- 题目地址: [https://leetcode-cn.com/problems/qiu-12n-lcof](https://leetcode-cn.com/problems/qiu-12n-lcof)
- 执行时间: 0 ms
- 内存消耗: 6.4 MB
- 通过日期: 2020-04-27 19:47

## 题目内容
<p>求 <code>1+2+...+n</code> ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> n = 3
<strong>输出: </strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> n = 9
<strong>输出: </strong>45
</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= n <= 10000</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};

```