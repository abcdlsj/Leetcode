# Largest Time for Given Digits *
- 题目地址: [https://leetcode-cn.com/problems/largest-time-for-given-digits](https://leetcode-cn.com/problems/largest-time-for-given-digits)
- 执行时间: 0 ms
- 内存消耗: 8.3 MB
- 通过日期: 2019-09-04 21:20

## 题目内容
<p>给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。</p>

<p>最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。</p>

<p>以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[1,2,3,4]
<strong>输出：</strong>"23:41"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[5,5,5,5]
<strong>输出：</strong>""
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>A.length == 4</code></li>
	<li><code>0 <= A[i] <= 9</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
		int res = -1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)if (j != i)
				for (int k = 0; k < 4; k++)if (k != i && k != j) {
					int l = 6 - i - j - k;
					int hours = 10 * A[i] + A[j];
					int mins = 10 * A[k] + A[l];
					if (hours < 24 && mins < 60)
						res = max(res, hours * 60 + mins);
				}
		if (res >= 0) {
			char c[6];
			sprintf(c, "%.2d:%.2d", res / 60, res % 60);
			return c;
		}
		return "";
    }
};

```