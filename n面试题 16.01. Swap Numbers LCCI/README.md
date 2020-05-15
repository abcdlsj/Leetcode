# Swap Numbers LCCI **
- 题目地址: [https://leetcode-cn.com/problems/swap-numbers-lcci](https://leetcode-cn.com/problems/swap-numbers-lcci)
- 执行时间: 0 ms
- 内存消耗: 7.4 MB
- 通过日期: 2020-05-15 11:09

## 题目内容
<p>编写一个函数，不用临时变量，直接交换<code>numbers = [a, b]</code>中<code>a</code>与<code>b</code>的值。</p>
<p><strong>示例：</strong></p>
<pre><strong>输入:</strong> numbers = [1,2]
<strong>输出:</strong> [2,1]
</pre>
<p><strong>提示：</strong></p>
<ul>
<li><code>numbers.length == 2</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;
    }
};

```