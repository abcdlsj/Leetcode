# Coin Change **
- 题目地址: [https://leetcode-cn.com/problems/coin-change](https://leetcode-cn.com/problems/coin-change)
- 执行时间: 96 ms
- 内存消耗: 16.3 MB
- 通过日期: 2020-03-09 16:46

## 题目内容
<p>给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 <code>-1</code>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>coins = <code>[1, 2, 5]</code>, amount = <code>11</code>
<strong>输出: </strong><code>3</code> 
<strong>解释:</strong> 11 = 5 + 5 + 1</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>coins = <code>[2]</code>, amount = <code>3</code>
<strong>输出: </strong>-1</pre>

<p><strong>说明</strong>:<br>
你可以认为每种硬币的数量是无限的。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        vector<int> dp(amount + 1, max);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            for(int j = 0; j < coins.size(); ++j) {
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == max? -1:dp[amount];
        }
};

```