# Count Negative Numbers in a Sorted Matrix *
- 题目地址: [https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix](https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix)
- 执行时间: 16 ms
- 内存消耗: 10.4 MB
- 通过日期: 2020-02-16 10:46

## 题目内容
<p>给你一个 <code>m * n</code> 的矩阵 <code>grid</code>，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 </p>

<p>请你统计并返回 <code>grid</code> 中 <strong>负数</strong> 的数目。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
<strong>输出：</strong>8
<strong>解释：</strong>矩阵中共有 8 个负数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[3,2],[1,0]]
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,-1],[-1,-1]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[-1]]
<strong>输出：</strong>1
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>-100 <= grid[i][j] <= 100</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int ans = 0;
      int m = grid.size();
      int n = grid[0].size();
      for(int i = 0;i < m;i++){
        for(int j=0;j< n;j++){
          if(grid[i][j]<0) {
            ans+=n-j;
            break;
          }
        }
      }
      return ans;
    }
};

```