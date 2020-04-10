# Smallest Difference LCCI **
- 题目地址: [https://leetcode-cn.com/problems/smallest-difference-lcci](https://leetcode-cn.com/problems/smallest-difference-lcci)
- 执行时间: 324 ms
- 内存消耗: 35.9 MB
- 通过日期: 2020-04-03 20:46

## 题目内容
<p>给定两个整数数组<code>a</code>和<code>b</code>，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差</p>
<p><strong>示例：</strong></p>
<pre><strong>输入：</strong>{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
<strong>输出：</strong> 3，即数值对(11, 8)
</pre>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 <= a.length, b.length <= 100000</code></li>
<li><code>-2147483648 <= a[i], b[i] <= 2147483647</code></li>
<li>正确结果在区间[-2147483648, 2147483647]内</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        long res = INT_MAX;
        while(i < a.size() && j < b.size()) {
            res = min(res, abs((long)a[i] - b[j]));
            if(a[i] <= b[j]) i++;
            else j++;
        }
        return res;
    } 
};

```