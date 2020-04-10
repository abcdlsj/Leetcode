# Rotate Matrix LCCI **
- 题目地址: [https://leetcode-cn.com/problems/rotate-matrix-lcci](https://leetcode-cn.com/problems/rotate-matrix-lcci)
- 执行时间: 4 ms
- 内存消耗: 7.2 MB
- 通过日期: 2020-04-07 17:18

## 题目内容
<p>给你一幅由 <code>N × N</code> 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。</p>

<p>不占用额外内存空间能否做到？</p>



<p><strong>示例 1:</strong></p>

<pre>给定 <strong>matrix</strong> = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

<strong>原地</strong>旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
</pre>

<p><strong>示例 2:</strong></p>

<pre>给定 <strong>matrix</strong> =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

<strong>原地</strong>旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int row = (n - 2) / 2, col = (n - 1) / 2;
        for(int i = 0; i <= row; i++) {
            for(int j = 0; j <= col; j++) {
                swap(matrix[i][j], matrix[j][n - i -1]);
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
                swap(matrix[i][j], matrix[n - j - 1][i]);
            }
        }
    }
};

```