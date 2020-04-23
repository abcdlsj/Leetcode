# Coin LCCI **
- 题目地址: [https://leetcode-cn.com/problems/coin-lcci](https://leetcode-cn.com/problems/coin-lcci)
- 执行时间: 100 ms
- 内存消耗: 14.3 MB
- 通过日期: 2020-04-23 10:11

## 题目内容
<p>硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)</p>

<p> <strong>示例1:</strong></p>

<pre>
<strong> 输入</strong>: n = 5
<strong> 输出</strong>：2
<strong> 解释</strong>: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
</pre>

<p> <strong>示例2:</strong></p>

<pre>
<strong> 输入</strong>: n = 10
<strong> 输出</strong>：4
<strong> 解释</strong>: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1
</pre>

<p> <strong>说明：</strong></p>

<p>注意:</p>

<p>你可以假设：</p>

<ul>
<li>0 <= n (总金额) <= 1000000</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1), coins = {1, 5, 10, 25};
        dp[0] = 1;
        for(int i = 0; i < 4; i++) {
            for(int j = coins[i]; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
            }
        }
        return dp[n];
    }
};

```