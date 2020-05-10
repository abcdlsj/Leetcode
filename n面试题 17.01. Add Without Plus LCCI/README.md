# Add Without Plus LCCI *
- 题目地址: [https://leetcode-cn.com/problems/add-without-plus-lcci](https://leetcode-cn.com/problems/add-without-plus-lcci)
- 执行时间: 0 ms
- 内存消耗: 6 MB
- 通过日期: 2020-05-08 15:20

## 题目内容
<p>设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。</p>

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
        // if(b == 0) return a;
        // return add(a ^ b, ((unsigned int)a & b) << 1);
        while(b != 0) {
            int tmpa = a ^ b, tmpb = (unsigned int)(a & b) << 1;
            a = tmpa, b = tmpb;
        }
        return a;
    }
};

```