# 丑数 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/chou-shu-lcof](https://leetcode-cn.com/problems/chou-shu-lcof)
- 执行时间: 8 ms
- 内存消耗: 7.6 MB
- 通过日期: 2020-04-19 08:18

## 题目内容
<p>我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> n = 10
<strong>输出:</strong> 12
<strong>解释: </strong><code>1, 2, 3, 4, 5, 6, 8, 9, 10, 12</code> 是前 10 个丑数。</pre>

<p><strong>说明: </strong> </p>

<ol>
	<li><code>1</code> 是丑数。</li>
	<li><code>n</code> <strong>不超过</strong>1690。</li>
</ol>

<p>注意：本题与主站 264 题相同：<a href="https://leetcode-cn.com/problems/ugly-number-ii/">https://leetcode-cn.com/problems/ugly-number-ii/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> cnt(n, 0);
        cnt[0] = 1;
        int x = 0, y = 0, z = 0;
        for(int i = 1; i < n; i++) {
            cnt[i] = min(cnt[x] * 2, min(cnt[y] * 3, cnt[z] * 5));
            if(cnt[i] == cnt[x] * 2) x++;
            if(cnt[i] == cnt[y] * 3) y++;
            if(cnt[i] == cnt[z] * 5) z++;
        }
        return cnt[n - 1];
    }
};

```