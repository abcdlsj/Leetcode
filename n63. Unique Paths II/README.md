# Unique Paths II **
- 题目地址: [https://leetcode-cn.com/problems/unique-paths-ii](https://leetcode-cn.com/problems/unique-paths-ii)
- 执行时间: 0 ms
- 内存消耗: 7.2 MB
- 通过日期: 2020-04-26 11:16

## 题目内容
<p>一个机器人位于一个 <em>m x n </em>网格的左上角 （起始点在下图中标记为“Start” ）。</p>

<p>机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。</p>

<p>现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png" style="height: 183px; width: 400px;"></p>

<p>网格中的障碍物和空位置分别用 <code>1</code> 和 <code>0</code> 来表示。</p>

<p><strong>说明：</strong><em>m</em> 和 <em>n </em>的值均不超过 100。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:
</strong>[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
<strong>输出:</strong> 2
<strong>解释:</strong>
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 <code>2</code> 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return  0;
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<long>> dp(row, vector<long> (col, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if(i == 0 && j == 0) dp[i][j] = 1;
                    else if(i == 0) dp[i][j] = dp[i][j-1];
                    else if(j == 0) dp[i][j] = dp[i-1][j]; 
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};

```