# Valid Boomerang 
- 题目地址: [https://leetcode-cn.com/problems/valid-boomerang](https://leetcode-cn.com/problems/valid-boomerang)
- 执行时间: 4 ms
- 内存消耗: 8.2 MB
- 通过日期: 2019-08-26 16:24

## 题目内容
<p>回旋镖定义为一组三个点，这些点各不相同且<strong>不</strong>在一条直线上。</p>

<p>给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[[1,1],[2,3],[3,2]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[1,1],[2,2],[3,3]]
<strong>输出：</strong>false</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>points.length == 3</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 <= points[i][j] <= 100</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
         return (points[2][1]-points[1][1])*(points[0][0]-points[1][0]) != (points[0][1]-points[1][1])*(points[2][0]-points[1][0]);
    }
};

```