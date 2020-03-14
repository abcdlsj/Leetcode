# Pascal's Triangle II *
- 题目地址: [https://leetcode-cn.com/problems/pascals-triangle-ii](https://leetcode-cn.com/problems/pascals-triangle-ii)
- 执行时间: 4 ms
- 内存消耗: 8 MB
- 通过日期: 2020-03-11 09:55

## 题目内容
<p>给定一个非负索引 <em>k</em>，其中 <em>k</em> ≤ 33，返回杨辉三角的第 <em>k </em>行。</p>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif"></p>

<p><small>在杨辉三角中，每个数是它左上方和右上方的数的和。</small></p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 3
<strong>输出:</strong> [1,3,3,1]
</pre>

<p><strong>进阶：</strong></p>

<p>你可以优化你的算法到 <em>O</em>(<em>k</em>) 空间复杂度吗？</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i = 0; i <= rowIndex; ++i){
            result.push_back(1);
            for(int j = i - 1; j > 0; --j){
                result[j] += result[j - 1];
            }
        }
        return result;
    }
};

```