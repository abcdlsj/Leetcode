# Reverse Integer *
- 题目地址: [https://leetcode-cn.com/problems/reverse-integer](https://leetcode-cn.com/problems/reverse-integer)
- 执行时间: 4 ms
- 内存消耗: 7.5 MB
- 通过日期: 2020-03-20 12:22

## 题目内容
<p>给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 123
<strong>输出:</strong> 321
</pre>

<p><strong> 示例 2:</strong></p>

<pre><strong>输入:</strong> -123
<strong>输出:</strong> -321
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 120
<strong>输出:</strong> 21
</pre>

<p><strong>注意:</strong></p>

<p>假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2<sup>31</sup>,  2<sup>31 </sup>− 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x) {
            int pop = x%10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
            rev = rev*10 + pop;
        }
        return rev;
    }
};

```