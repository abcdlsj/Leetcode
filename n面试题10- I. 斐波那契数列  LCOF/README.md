# 斐波那契数列  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof)
- 执行时间: 4 ms
- 内存消耗: 8.2 MB
- 通过日期: 2020-03-06 09:57

## 题目内容
<p>写一个函数，输入 <code>n</code> ，求斐波那契（Fibonacci）数列的第 <code>n</code> 项。斐波那契数列的定义如下：</p>

<pre>F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.</pre>

<p>斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。</p>

<p>答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>5
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= n <= 100</code></li>
</ul>

<p>注意：本题与主站 509 题相同：<a href="https://leetcode-cn.com/problems/fibonacci-number/">https://leetcode-cn.com/problems/fibonacci-number/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
	int fib(int n) {
        if(n == 0 || n == 1) return n;
        int a = 1, b = 0;
        for(int i = 2; i <= n; ++i) {
            a = a + b;
            b = a - b;
            a %= 1000000007;
        }
        return a;
    }
};

```