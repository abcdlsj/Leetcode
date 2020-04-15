# 不用加减乘除做加法 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof](https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof)
- 执行时间: 0 ms
- 内存消耗: 5.9 MB
- 通过日期: 2020-04-14 21:05

## 题目内容
<p>写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> a = 1, b = 1
<strong>输出:</strong> 2</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>a</code>, <code>b</code> 均可能是负数或 0</li>
	<li>结果不会溢出 32 位整数</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int add(int a, int b) {
        while(b != 0) {
            int tmpa = a ^ b;
            int tmpb = ((unsigned int)(a & b) << 1);
            a = tmpa;
            b = tmpb;
        }
        return a;
    }
};

```