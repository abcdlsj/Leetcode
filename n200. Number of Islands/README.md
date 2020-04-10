# Number of Islands **
- 题目地址: [https://leetcode-cn.com/problems/number-of-islands](https://leetcode-cn.com/problems/number-of-islands)
- 执行时间: 16 ms
- 内存消耗: 8.4 MB
- 通过日期: 2020-04-09 09:59

## 题目内容
<p>给定一个由 <code>'1'</code>（陆地）和 <code>'0'</code>（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。</p>

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
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void infect(int i, int j, vector<vector<char>>& grid) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '2' || grid[i][j] == '0')
            return;
        else {
            grid[i][j] = '2';
            infect(i-1, j, grid);
            infect(i+1, j, grid);
            infect(i, j+1, grid);
            infect(i, j-1, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    infect(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
};

```