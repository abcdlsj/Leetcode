# Rotting Oranges **
- 题目地址: [https://leetcode-cn.com/problems/rotting-oranges](https://leetcode-cn.com/problems/rotting-oranges)
- 执行时间: 8 ms
- 内存消耗: 14.1 MB
- 通过日期: 2020-03-14 17:50

## 题目内容
<p>在给定的网格中，每个单元格可以有以下三个值之一：</p>

<ul>
	<li>值 <code>0</code> 代表空单元格；</li>
	<li>值 <code>1</code> 代表新鲜橘子；</li>
	<li>值 <code>2</code> 代表腐烂的橘子。</li>
</ul>

<p>每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。</p>

<p>返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 <code>-1</code>。</p>



<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/16/oranges.png" style="height: 150px; width: 712px;"></strong></p>

<pre><strong>输入：</strong>[[2,1,1],[1,1,0],[0,1,1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[2,1,1],[0,1,1],[1,0,1]]
<strong>输出：</strong>-1
<strong>解释：</strong>左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[[0,2]]
<strong>输出：</strong>0
<strong>解释：</strong>因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= grid.length <= 10</code></li>
	<li><code>1 <= grid[0].length <= 10</code></li>
	<li><code>grid[i][j]</code> 仅为 <code>0</code>、<code>1</code> 或 <code>2</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
    int cnt;
    int dis[10][10];
    int dir_x[4]={0, 1, 0, -1};
    int dir_y[4]={1, 0, -1, 0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> >Q;
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int n=(int)grid.size(), m=(int)grid[0].size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 2){
                    Q.push(make_pair(i, j));
                    dis[i][j] = 0;
                }
                else if (grid[i][j] == 1) cnt += 1;
            }
        }
        while (!Q.empty()){
            pair<int,int> x = Q.front();Q.pop();
            for (int i = 0; i < 4; ++i){
                int tx = x.first + dir_x[i];
                int ty = x.second + dir_y[i];
                if (tx < 0|| tx >= n || ty < 0|| ty >= m|| ~dis[tx][ty] || !grid[tx][ty]) continue;
                dis[tx][ty] = dis[x.first][x.second] + 1;
                Q.push(make_pair(tx, ty));
                if (grid[tx][ty] == 1){
                    cnt -= 1;
                    ans = dis[tx][ty];
                    if (!cnt) break;
                }
            }
        }
        return cnt ? -1 : ans;
    }
};

```