# 顺时针打印矩阵  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof)
- 执行时间: 20 ms
- 内存消耗: 9.9 MB
- 通过日期: 2020-04-13 14:45

## 题目内容
<p>输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,2,3,6,9,8,7,4,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>输出：</strong>[1,2,3,4,8,12,11,10,9,5,6,7]
</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>0 <= matrix.length <= 100</code></li>
	<li><code>0 <= matrix[i].length <= 100</code></li>
</ul>

<p>注意：本题与主站 54 题相同：<a href="https://leetcode-cn.com/problems/spiral-matrix/">https://leetcode-cn.com/problems/spiral-matrix/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        while(true) {
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            if(++top > bottom) break;
            for(int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
            if(--bottom < top) break;
            for(int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return res;
    }
};

```