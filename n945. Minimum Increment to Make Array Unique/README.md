# Minimum Increment to Make Array Unique **
- 题目地址: [https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique](https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique)
- 执行时间: 128 ms
- 内存消耗: 26 MB
- 通过日期: 2020-03-22 10:08

## 题目内容
<p>给定整数数组 A，每次 <em>move</em> 操作将会选择任意 <code>A[i]</code>，并将其递增 <code>1</code>。</p>

<p>返回使 <code>A</code> 中的每个值都是唯一的最少操作次数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入：</strong>[1,2,2]
<strong>输出：</strong>1
<strong>解释：</strong>经过一次 <em>move</em> 操作，数组将变为 [1, 2, 3]。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入：</strong>[3,2,1,2,1,7]
<strong>输出：</strong>6
<strong>解释：</strong>经过 6 次 <em>move</em> 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 <em>move</em> 操作是不能让数组的每个值唯一的。
</pre>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 <= A.length <= 40000</code></li>
	<li><code>0 <= A[i] < 40000</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        if(A.size() <= 1) return 0;
        for(int i = 1; i < A.size(); i++) {
            if(A[i-1] >= A[i]) {
                ans += A[i-1] - A[i] + 1;
                A[i] = A[i-1] + 1;
            }
        }
        return ans;
    }
};

```