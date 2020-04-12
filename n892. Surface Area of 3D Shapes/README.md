# Surface Area of 3D Shapes *
- 题目地址: [https://leetcode-cn.com/problems/surface-area-of-3d-shapes](https://leetcode-cn.com/problems/surface-area-of-3d-shapes)
- 执行时间: 16 ms
- 内存消耗: 8.7 MB
- 通过日期: 2020-03-25 21:11

## 题目内容
<p>在 <code>N * N</code> 的网格上，我们放置一些 <code>1 * 1 * 1 </code> 的立方体。</p>

<p>每个值 <code>v = grid[i][j]</code> 表示 <code>v</code> 个正方体叠放在对应单元格 <code>(i, j)</code> 上。</p>

<p>请你返回最终形体的表面积。</p>



<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[[2]]
<strong>输出：</strong>10
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[1,2],[3,4]]
<strong>输出：</strong>34
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[[1,0],[0,2]]
<strong>输出：</strong>16
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>[[1,1,1],[1,0,1],[1,1,1]]
<strong>输出：</strong>32
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>[[2,2,2],[2,1,2],[2,2,2]]
<strong>输出：</strong>46
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= N <= 50</code></li>
	<li><code>0 <= grid[i][j] <= 50</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] > 0) {
                    res += grid[i][j]*6 - (grid[i][j] - 1)*2;
                }
                if(i > 0) {
                    res -= min(grid[i][j], grid[i-1][j])*2;
                }
                if(j > 0) {
                    res -= min(grid[i][j], grid[i][j-1])*2;
                }
            }
        }
        return res;
    }
};

```