# 二进制中1的个数 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof)
- 执行时间: 0 ms
- 内存消耗: 5.9 MB
- 通过日期: 2020-04-10 09:31

## 题目内容
<p>请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>00000000000000000000000000001011
<strong>输出：</strong>3
<strong>解释：</strong>输入的二进制串 <code><strong>00000000000000000000000000001011</strong> 中，共有三位为 '1'。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>00000000000000000000000010000000
<strong>输出：</strong>1
<strong>解释：</strong>输入的二进制串 <strong>00000000000000000000000010000000</strong> 中，共有一位为 '1'。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>11111111111111111111111111111101
<strong>输出：</strong>31
<strong>解释：</strong>输入的二进制串 <strong>11111111111111111111111111111101</strong> 中，共有 31 位为 '1'。</pre>



<p>注意：本题与主站 191 题相同：<a href="https://leetcode-cn.com/problems/number-of-1-bits/">https://leetcode-cn.com/problems/number-of-1-bits/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        // while(n != 0) {
        //     ans += n & 1;
        //     n = n >> 1;
        // }

        while(n != 0) {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
};

```