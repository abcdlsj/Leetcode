# Number of Closed Islands **
- 题目地址: [https://leetcode-cn.com/problems/number-of-closed-islands](https://leetcode-cn.com/problems/number-of-closed-islands)
- 执行时间: 20 ms
- 内存消耗: 9.1 MB
- 通过日期: 2020-04-09 17:37

## 题目内容
<p>有一个二维矩阵 <code>grid</code> ，每个位置要么是陆地（记号为 <code>0</code> ）要么是水域（记号为 <code>1</code> ）。</p>

<p>我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「<strong>岛屿</strong>」。</p>

<p>如果一座岛屿 <strong>完全</strong> 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「<strong>封闭岛屿</strong>」。</p>

<p>请返回封闭岛屿的数目。</p>



<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/07/sample_3_1610.png"></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/07/sample_4_1610.png"></p>

<pre><strong>输入：</strong>grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1,1,1,1],
             [1,0,0,0,0,0,1],
             [1,0,1,1,1,0,1],
             [1,0,1,0,1,0,1],
             [1,0,1,1,1,0,1],
             [1,0,0,0,0,0,1],
             [1,1,1,1,1,1,1]]
<strong>输出：</strong>2
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= grid.length, grid[0].length <= 100</code></li>
	<li><code>0 <= grid[i][j] <=1</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int val = 1;
                    dfs(grid, i, j, val);
                    ans += val;
                }
            }
        }

        return ans;

    }
    void dfs(vector<vector<int>> &grid, int i, int j, int &val) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            val = 0;
            return;
        }

        if(grid[i][j] != 0) return;
        grid[i][j] = 1;

        dfs(grid, i + 1, j, val);
        dfs(grid, i - 1, j, val);
        dfs(grid, i, j - 1, val);
        dfs(grid, i, j + 1, val);
    }
};

```