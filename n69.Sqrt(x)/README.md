# Sqrt(x) 
- 题目地址: [https://leetcode-cn.com/problems/sqrtx](https://leetcode-cn.com/problems/sqrtx)
- 执行时间: 16 ms
- 内存消耗: 8.2 MB
- 通过日期: 2019-08-29 10:41

## 题目内容
<p>实现 <code>int sqrt(int x)</code> 函数。</p>

<p>计算并返回 <em>x</em> 的平方根，其中 <em>x </em>是非负整数。</p>

<p>由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 4
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 8
<strong>输出:</strong> 2
<strong>说明:</strong> 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x)
    {
        if(x==0) return 0;
        long res=x;
        while(res*res>x)
            res=(res+x/res)/2;
        return (int)res; 
    }
};



```