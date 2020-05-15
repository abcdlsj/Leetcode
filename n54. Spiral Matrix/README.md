# Spiral Matrix **
- 题目地址: [https://leetcode-cn.com/problems/spiral-matrix](https://leetcode-cn.com/problems/spiral-matrix)
- 执行时间: 4 ms
- 内存消耗: 6.8 MB
- 通过日期: 2020-05-14 17:49

## 题目内容
<p>给定一个包含 <em>m</em> x <em>n</em> 个元素的矩阵（<em>m</em> 行, <em>n</em> 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
<strong>输出:</strong> [1,2,3,6,9,8,7,4,5]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
<strong>输出:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return {};
        int top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> res;

        while(true) {
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            if(++top > bot) break;
            for(int i = top; i <= bot; i++) res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--) res.push_back(matrix[bot][i]);
            if(--bot < top) break;
            for(int i = bot; i >= top; i--) res.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return res;
    }
};

```