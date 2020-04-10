# Integer Break **
- 题目地址: [https://leetcode-cn.com/problems/integer-break](https://leetcode-cn.com/problems/integer-break)
- 执行时间: 4 ms
- 内存消耗: 6.1 MB
- 通过日期: 2020-04-10 09:10

## 题目内容
<p>给定一个正整数 <em>n</em>，将其拆分为<strong>至少</strong>两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>2
<strong>输出: </strong>1
<strong>解释: </strong>2 = 1 + 1, 1 × 1 = 1。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>10
<strong>输出: </strong>36
<strong>解释: </strong>10 = 3 + 3 + 4, 3 × 3 × 4 = 36。</pre>

<p><strong>说明: </strong>你可以假设 <em>n </em>不小于 2 且不大于 58。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int integerBreak(int n) {
        // if(n == 2) return 1;
        // if(n == 3) return 2;
        // int ans = 1;
        // while(n > 4) {
        //     n -= 3;
        //     ans *= 3;
        // }
        // return ans * n;
        
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