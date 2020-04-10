# 剪绳子  LCOF **
- 题目地址: [https://leetcode-cn.com/problems/jian-sheng-zi-lcof](https://leetcode-cn.com/problems/jian-sheng-zi-lcof)
- 执行时间: 0 ms
- 内存消耗: 6.2 MB
- 通过日期: 2020-04-10 09:13

## 题目内容
<p>给你一根长度为 <code>n</code> 的绳子，请把绳子剪成整数长度的 <code>m</code> 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 <code>k[0],k[1]...k[m]</code> 。请问 <code>k[0]*k[1]*...*k[m]</code> 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。</p>

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
	<li><code>2 <= n <= 58</code></li>
</ul>

<p>注意：本题与主站 343 题相同：<a href="https://leetcode-cn.com/problems/integer-break/">https://leetcode-cn.com/problems/integer-break/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 1);
        
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }

        return dp[n];
    }
};

```