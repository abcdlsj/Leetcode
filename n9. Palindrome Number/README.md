# Palindrome Number *
- 题目地址: [https://leetcode-cn.com/problems/palindrome-number](https://leetcode-cn.com/problems/palindrome-number)
- 执行时间: 24 ms
- 内存消耗: 7.6 MB
- 通过日期: 2020-03-20 12:30

## 题目内容
<p>判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 121
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> -121
<strong>输出:</strong> false
<strong>解释:</strong> 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> false
<strong>解释:</strong> 从右向左读, 为 01 。因此它不是一个回文数。
</pre>

<p><strong>进阶:</strong></p>

<p>你能不将整数转为字符串来解决这个问题吗？</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int rev = 0, tmp = x;
        while(tmp) {
            int pop = tmp % 10; tmp /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX && pop > 7)) return false;
            if(rev < INT_MIN/10 || (rev == INT_MIN && pop < -8)) return false;
            rev = rev * 10 + pop;
        }   
        if(rev == x) return true;
        else return false;
    }
};

```