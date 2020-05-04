# Get Kth Magic Number LCCI **
- 题目地址: [https://leetcode-cn.com/problems/get-kth-magic-number-lcci](https://leetcode-cn.com/problems/get-kth-magic-number-lcci)
- 执行时间: 0 ms
- 内存消耗: 6.1 MB
- 通过日期: 2020-04-30 23:09

## 题目内容
<p>有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>k = 5

<strong>输出: </strong>9
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int getKthMagicNumber(int k) {
        // vector<int> dp(k + 1);
        // int p3 = 0, p5 = 0, p7 = 0;
        // dp[0] = 1;
        // if(k == 1) return dp[0];
        // for(int i = 1; i < k; i++) {
        //     dp[i] = min(dp[p3] * 3, min(dp[p5] * 5, dp[p7] * 7));
        //     if(dp[i] == dp[p3] * 3) p3++;
        //     if(dp[i] == dp[p5] * 5) p5++;
        //     if(dp[i] == dp[p7] * 7) p7++;
        // }
        // return dp[k - 1];
        if(k == 1) return 1;
        vector<int> dp(k);
        int p3 = 0, p5 = 0, p7 = 0;
        dp[0] = 1;
        for(int i = 1; i < k; i++) {
            dp[i] = min(dp[p3] * 3, min(dp[p5] * 5, dp[p7] * 7));
            if(dp[i] == dp[p3] * 3) p3++;
            if(dp[i] == dp[p5] * 5) p5++;
            if(dp[i] == dp[p7] * 7) p7++;
        }
        return dp[k - 1];
    }
};

```