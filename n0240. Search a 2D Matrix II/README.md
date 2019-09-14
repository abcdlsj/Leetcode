# Search a 2D Matrix II **
- 题目地址: [https://leetcode-cn.com/problems/search-a-2d-matrix-ii](https://leetcode-cn.com/problems/search-a-2d-matrix-ii)
- 执行时间: 112 ms 
- 内存消耗: 12.7 MB
- 通过日期: 2019-08-27 10:37

## 题目内容
<p>编写一个高效的算法来搜索 <em>m</em> x <em>n</em> 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：</p>

<ul>
	<li>每行的元素从左到右升序排列。</li>
	<li>每列的元素从上到下升序排列。</li>
</ul>

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


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int i=0,j=matrix[0].size()-1,cnt=0;
        while(i<matrix.size()&&j>=0)
        {
            cnt=matrix[i][j];
            if(cnt==target) return true;
            else if(cnt<target) i++;
            else j--;
        }
        return false;
    }
};

```