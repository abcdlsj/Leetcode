# 剪绳子 II LCOF **
- 题目地址: [https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof](https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof)
- 执行时间: 4 ms
- 内存消耗: 6 MB
- 通过日期: 2020-04-10 09:23

## 题目内容
<p>给你一根长度为 <code>n</code> 的绳子，请把绳子剪成整数长度的 <code>m</code> 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 <code>k[0],k[1]...k[m]</code> 。请问 <code>k[0]*k[1]*...*k[m]</code> 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。</p>

<p>答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入: </strong>2
<strong>输出: </strong>1
<strong>解释: </strong>2 = 1 + 1, 1 × 1 = 1</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>10
<strong>输出: </strong>36
<strong>解释: </strong>10 = 3 + 3 + 4, 3 × 3 × 4 = 36</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 1000</code></li>
</ul>

<p>注意：本题与主站 343 题相同：<a href="https://leetcode-cn.com/problems/integer-break/">https://leetcode-cn.com/problems/integer-break/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        
        long long ans = 1;
        while(n > 4) {
            n -= 3;
            ans *= 3;
            ans %= 1000000007;
        }

        return (int)(ans * n % 1000000007);
    }
};

```