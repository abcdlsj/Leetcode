# Search a 2D Matrix **
- 题目地址: [https://leetcode-cn.com/problems/search-a-2d-matrix](https://leetcode-cn.com/problems/search-a-2d-matrix)
- 执行时间: 4 ms
- 内存消耗: 7.5 MB
- 通过日期: 2020-05-14 21:19

## 题目内容
<p>编写一个高效的算法来判断 <em>m</em> x <em>n</em> 矩阵中，是否存在一个目标值。该矩阵具有如下特性：</p>

<ul>
	<li>每行中的整数从左到右按升序排列。</li>
	<li>每行的第一个整数大于前一行的最后一个整数。</li>
</ul>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
<strong>输出:</strong> false</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int m = matrix.size(), n = matrix[0].size();
        int begin = 0, mid, end = m * n - 1;
        while(begin < end) {
            mid = begin + (end - begin) / 2;
            if(matrix[mid / n][mid % n] < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }

        return matrix[begin / n][begin % n] == target;
    }
};

```