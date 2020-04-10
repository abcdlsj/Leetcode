# Power of Two *
- 题目地址: [https://leetcode-cn.com/problems/power-of-two](https://leetcode-cn.com/problems/power-of-two)
- 执行时间: 8 ms
- 内存消耗: 7.3 MB
- 通过日期: 2020-03-20 12:48

## 题目内容
<p>给定一个整数，编写一个函数来判断它是否是 2 的幂次方。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1
<strong>输出:</strong> true
<strong>解释: </strong>2<sup>0</sup> = 1</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 16
<strong>输出:</strong> true
<strong>解释: </strong>2<sup>4</sup> = 16</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 218
<strong>输出:</strong> false</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>2) {
            if(n % 2 == 1) return false;        
            else n = n / 2;
        }
        if(n == 2 || n == 1) return true;
        else return false;
    }
};

```