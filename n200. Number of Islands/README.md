# Number of Islands **
- 题目地址: [https://leetcode-cn.com/problems/number-of-islands](https://leetcode-cn.com/problems/number-of-islands)
- 执行时间: 20 ms
- 内存消耗: 8.3 MB
- 通过日期: 2020-04-20 20:16

## 题目内容
<p>给你一个由 <code>'1'</code>（陆地）和 <code>'0'</code>（水）组成的的二维网格，请你计算网格中岛屿的数量。</p>

<p>岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。</p>

<p>此外，你可以假设该网格的四条边均被水包围。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
11110
11010
11000
00000
<strong>输出:</strong> 1
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
11000
11000
00100
00011
<strong>输出: </strong>3
<strong>解释: </strong>每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '2' || grid[row][col] == '0') return;
        grid[row][col] = '2';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1); 
    }
};

```