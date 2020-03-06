# 青蛙跳台阶问题  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof)
- 执行时间: 0 ms
- 内存消耗: 8.2 MB
- 通过日期: 2020-03-06 10:02

## 题目内容
<p>一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 <code>n</code> 级的台阶总共有多少种跳法。</p>

<p>答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>21
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
    int numWays(int n) {
        if(n == 0 || n == 1) return 1;
        int a = 1, b = 1;
        for(int i = 2; i <= n; ++i) {
            a = a + b;
            b = a - b;
            a %= 1000000007;
        }
        return a;
    }
};

```