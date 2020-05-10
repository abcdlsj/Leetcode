# Set Matrix Zeroes **
- 题目地址: [https://leetcode-cn.com/problems/set-matrix-zeroes](https://leetcode-cn.com/problems/set-matrix-zeroes)
- 执行时间: 8 ms
- 内存消耗: 8.9 MB
- 通过日期: 2020-04-25 19:40

## 题目内容
<p>给定一个 <em>m</em> x <em>n</em> 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用<strong><a href="http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">原地</a></strong>算法<strong>。</strong></p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
<strong>输出:</strong> 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
<strong>输出:</strong> 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]</pre>

<p><strong>进阶:</strong></p>

<ul>
	<li>一个直接的解决方案是使用  O(<em>m</em><em>n</em>) 的额外空间，但这并不是一个好的解决方案。</li>
	<li>一个简单的改进方案是使用 O(<em>m</em> + <em>n</em>) 的额外空间，但这仍然不是最好的解决方案。</li>
	<li>你能想出一个常数空间的解决方案吗？</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowlen = matrix.size(), colen = matrix[0].size();
        bool isrow = false, iscol = false;
        for(int i = 0; i < rowlen; i++) {
            if(matrix[i][0] == 0) {
                isrow = true;
                break;
            }
        }
        for(int i = 0; i < colen; i++) {
            if(matrix[0][i] == 0) {
                iscol = true;
                break;
            }
        }
        for(int i = 1; i < rowlen; i++) {
            for(int j = 1; j < colen; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < rowlen; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < colen; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < colen; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < rowlen; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(isrow) {
            for(int i = 0; i < rowlen; i++) {
                matrix[i][0] = 0;
            }
        }
        if(iscol) {
            for(int j = 0; j < colen; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

```