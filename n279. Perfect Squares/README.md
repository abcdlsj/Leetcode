# Perfect Squares **
- 题目地址: [https://leetcode-cn.com/problems/perfect-squares](https://leetcode-cn.com/problems/perfect-squares)
- 执行时间: 204 ms
- 内存消耗: 10.8 MB
- 通过日期: 2020-03-19 11:21

## 题目内容
<p>给定正整数 <em>n</em>，找到若干个完全平方数（比如 <code>1, 4, 9, 16, ...</code>）使得它们的和等于<em> n</em>。你需要让组成和的完全平方数的个数最少。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <em>n</em> = <code>12</code>
<strong>输出:</strong> 3 
<strong>解释: </strong><code>12 = 4 + 4 + 4.</code></pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <em>n</em> = <code>13</code>
<strong>输出:</strong> 2
<strong>解释: </strong><code>13 = 4 + 9.</code></pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i = 1; i <=n ; i++) {
            dp[i] = i;
            for(int j = 1; i - j*j >= 0; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};

```