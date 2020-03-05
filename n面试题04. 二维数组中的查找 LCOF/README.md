# 二维数组中的查找 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof)
- 执行时间: 36 ms
- 内存消耗: 15.4 MB
- 通过日期: 2020-03-05 14:36

## 题目内容
<p>在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。</p>



<p><strong>示例:</strong></p>

<p>现有矩阵 matrix 如下：</p>

<pre>[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
</pre>

<p>给定 target = <code>5</code>，返回 <code>true</code>。</p>

<p>给定 target = <code>20</code>，返回 <code>false</code>。</p>



<p><strong>限制：</strong></p>

<p><code>0 <= n <= 1000</code></p>

<p><code>0 <= m <= 1000</code></p>



<p><strong>注意：</strong>本题与主站 240 题相同：<a href="https://leetcode-cn.com/problems/search-a-2d-matrix-ii/">https://leetcode-cn.com/problems/search-a-2d-matrix-ii/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target){
        if(matrix.size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while(j >= 0&& i < n) {
            if(target == matrix[i][j]) return true; 
            if(target < matrix[i][j]) j--;
            else ++i;
        } 
        return false;
    }
};

```