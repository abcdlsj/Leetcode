# Convert Integer LCCI *
- 题目地址: [https://leetcode-cn.com/problems/convert-integer-lcci](https://leetcode-cn.com/problems/convert-integer-lcci)
- 执行时间: 0 ms
- 内存消耗: 6 MB
- 通过日期: 2020-05-04 11:54

## 题目内容
<p>整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。</p>

<p> <strong>示例1:</strong></p>

<pre>
<strong> 输入</strong>：A = 29 （或者0b11101）, B = 15（或者0b01111）
<strong> 输出</strong>：2
</pre>

<p> <strong>示例2:</strong></p>

<pre>
<strong> 输入</strong>：A = 1，B = 2
<strong> 输出</strong>：2
</pre>

<p> <strong>提示:</strong></p>

<ol>
<li>A，B范围在[-2147483648, 2147483647]之间</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned x = A ^ B; //必须使用 unsigned
        // 然后就是计算 x 中 1 的个数了
        int cnt = 0;
        while(x != 0) {
            x &= (x - 1);
            cnt++;
        }
        return cnt;
    }
};

```