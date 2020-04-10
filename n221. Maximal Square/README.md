# Maximal Square **
- 题目地址: [https://leetcode-cn.com/problems/maximal-square](https://leetcode-cn.com/problems/maximal-square)
- 执行时间: 24 ms
- 内存消耗: 8.8 MB
- 通过日期: 2020-04-09 09:52

## 题目内容
<p>在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入: 
</strong>
1 0 1 0 0
1 0 <strong>1 1</strong> 1
1 1 <strong>1 1 </strong>1
1 0 0 1 0

<strong>输出: </strong>4</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() < 1 || matrix[0].size() < 1) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;

        vector<vector<char>> dp(m + 1, vector<char> (n + 1, '0'));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
                    ans = max(ans, dp[i][j] - '0');
                }
            }
        }
        return ans * ans;
    }
};

```