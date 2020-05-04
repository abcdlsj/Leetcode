# 数值的整数次方 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof)
- 执行时间: 0 ms
- 内存消耗: 5.9 MB
- 通过日期: 2020-05-01 21:03

## 题目内容
<p>实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 2.00000, 10
<strong>输出:</strong> 1024.00000
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 2.10000, 3
<strong>输出:</strong> 9.26100
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 2.00000, -2
<strong>输出:</strong> 0.25000
<strong>解释:</strong> 2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25</pre>



<p><strong>说明:</strong></p>

<ul>
	<li>-100.0 < <em>x</em> < 100.0</li>
	<li><em>n</em> 是 32 位有符号整数，其数值范围是 [−2<sup>31</sup>, 2<sup>31 </sup>− 1] 。</li>
</ul>

<p>注意：本题与主站 50 题相同：<a href="https://leetcode-cn.com/problems/powx-n/">https://leetcode-cn.com/problems/powx-n/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    double myPow(double base, int n) {
        double res = 1;
        int exp = n;
        while(exp) {
            if(exp & 1) res = res * base;
            base = base * base;
            exp = exp / 2;
        }
        return n > 0 ? res : 1.0 / res;
    }
};

```