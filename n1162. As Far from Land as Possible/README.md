# As Far from Land as Possible **
- 题目地址: [https://leetcode-cn.com/problems/as-far-from-land-as-possible](https://leetcode-cn.com/problems/as-far-from-land-as-possible)
- 执行时间: 104 ms
- 内存消耗: 13.5 MB
- 通过日期: 2020-03-30 08:53

## 题目内容
<p>你现在手里有一份大小为 N x N 的「地图」（网格） <code>grid</code>，上面的每个「区域」（单元格）都用 <code>0</code> 和 <code>1</code> 标记好了。其中 <code>0</code> 代表海洋，<code>1</code> 代表陆地，请你找出一个海洋区域，这个海洋区域到离它最近的陆地区域的距离是最大的。</p>

<p>我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：<code>(x0, y0)</code> 和 <code>(x1, y1)</code> 这两个区域之间的距离是 <code>|x0 - x1| + |y0 - y1|</code> 。</p>

<p>如果我们的地图上只有陆地或者海洋，请返回 <code>-1</code>。</p>



<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/1336_ex1.jpeg" style="height: 87px; width: 185px;"></strong></p>

<pre><strong>输入：</strong>[[1,0,1],[0,0,0],[1,0,1]]
<strong>输出：</strong>2
<strong>解释： </strong>
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/1336_ex2.jpeg" style="height: 87px; width: 184px;"></strong></p>

<pre><strong>输入：</strong>[[1,0,0],[0,0,0],[0,0,0]]
<strong>输出：</strong>4
<strong>解释： </strong>
海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= grid.length == grid[0].length <= 100</code></li>
	<li><code>grid[i][j]</code> 不是 <code>0</code> 就是 <code>1</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int time = 0, land = 0, ocean = 0, N = grid.size();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 0) {
                    ocean ++;
                }
           }
        }
        vector<int> x = {-1, 1, 0, 0}, y = {0, 0, 1, -1};
        if(ocean == N*N || ocean == 0) return -1;
        while(ocean != 0) {
            time++;
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(grid[i][j] == time) {
                        for(int k = 0; k < 4; k++) {
                            if(i + x[k] >= 0 && i + x[k] < N && j + y[k] >= 0 && j + y[k] < N && grid[i + x[k]][j + y[k]] == 0) {
                                grid[i + x[k]][j + y[k]] = time + 1;
                                ocean --;
                            }
                        }
                    }
                }
            }
        }
        return time;
    }
};

```