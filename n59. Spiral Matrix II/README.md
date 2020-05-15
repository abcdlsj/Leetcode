# Spiral Matrix II **
- 题目地址: [https://leetcode-cn.com/problems/spiral-matrix-ii](https://leetcode-cn.com/problems/spiral-matrix-ii)
- 执行时间: 4 ms
- 内存消耗: 6.6 MB
- 通过日期: 2020-05-14 21:08

## 题目内容
<p>给定一个正整数 <em>n</em>，生成一个包含 1 到 <em>n</em><sup>2</sup> 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 3
<strong>输出:</strong>
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int left = 0, right = n - 1, top = 0, bot = n - 1, step = 1;
        while(step <= n * n) {
            for(int i = left; i <= right; i++) res[top][i] = step++;
            top++;
            for(int i = top; i <= bot; i++) res[i][right] = step++;
            right--;
            for(int i = right; i >= left; i--) res[bot][i] = step++;
            bot--;
            for(int i = bot; i >= top; i--) res[i][left] = step++;
            left++;
        }

        return res;
    }
};

```