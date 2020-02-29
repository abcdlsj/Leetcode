# Sort Array By Parity *
- 题目地址: [https://leetcode-cn.com/problems/sort-array-by-parity](https://leetcode-cn.com/problems/sort-array-by-parity)
- 执行时间: 16 ms
- 内存消耗: 18.5 MB
- 通过日期: 2020-02-28 13:53

## 题目内容
<p>给定一个非负整数数组 <code>A</code>，返回一个数组，在该数组中， <code>A</code> 的所有偶数元素之后跟着所有奇数元素。</p>

<p>你可以返回满足此条件的任何数组作为答案。</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[3,1,2,4]
<strong>输出：</strong>[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= A.length <= 5000</code></li>
	<li><code>0 <= A[i] <= 5000</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
双指针
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int i = 0, j = n - 1;
        while(i <= j) {
            if(A[i]%2==1&&A[j]%2==0)
                swap(A[i],A[j]);
            if(A[i]%2==0) ++i;
            if(A[j]%2==1) --j;
        }
        return A;
    }
};

```