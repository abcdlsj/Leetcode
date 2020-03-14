# Pascal's Triangle *
- 题目地址: [https://leetcode-cn.com/problems/pascals-triangle](https://leetcode-cn.com/problems/pascals-triangle)
- 执行时间: 0 ms
- 内存消耗: 8 MB
- 通过日期: 2020-03-11 09:38

## 题目内容
<p>给定一个非负整数 <em>numRows，</em>生成杨辉三角的前 <em>numRows </em>行。</p>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif"></p>

<p><small>在杨辉三角中，每个数是它左上方和右上方的数的和。</small></p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 5
<strong>输出:</strong>
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows == 0) return res;

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) res[i].push_back(1);
                else
                    res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
        }
        return res;
    }
};

```