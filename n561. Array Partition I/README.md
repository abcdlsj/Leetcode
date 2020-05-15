# Array Partition I *
- 题目地址: [https://leetcode-cn.com/problems/array-partition-i](https://leetcode-cn.com/problems/array-partition-i)
- 执行时间: 164 ms
- 内存消耗: 26.5 MB
- 通过日期: 2020-05-12 19:01

## 题目内容
<p>给定长度为 <strong>2n </strong>的数组, 你的任务是将这些数分成 <strong>n </strong>对, 例如 (a<sub>1</sub>, b<sub>1</sub>), (a<sub>2</sub>, b<sub>2</sub>), ..., (a<sub>n</sub>, b<sub>n</sub>) ，使得从1 到 n 的 min(a<sub>i</sub>, b<sub>i</sub>) 总和最大。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> [1,4,3,2]

<strong>输出:</strong> 4
<strong>解释:</strong> n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
</pre>

<p><strong>提示:</strong></p>

<ol>
	<li><strong>n</strong> 是正整数,范围在 [1, 10000].</li>
	<li>数组中的元素范围在 [-10000, 10000].</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};

```