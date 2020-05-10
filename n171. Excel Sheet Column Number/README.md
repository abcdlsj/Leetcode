# Excel Sheet Column Number *
- 题目地址: [https://leetcode-cn.com/problems/excel-sheet-column-number](https://leetcode-cn.com/problems/excel-sheet-column-number)
- 执行时间: 4 ms
- 内存消耗: 6.1 MB
- 通过日期: 2020-05-10 15:32

## 题目内容
<p>给定一个Excel表格中的列名称，返回其相应的列序号。</p>

<p>例如，</p>

<pre>    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
</pre>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "A"
<strong>输出:</strong> 1
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>"AB"
<strong>输出:</strong> 28
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入: </strong>"ZY"
<strong>输出:</strong> 701</pre>

<p><strong>致谢：</strong><br>
特别感谢 <a href="http://leetcode.com/discuss/user/ts">@ts</a> 添加此问题并创建所有测试用例。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int titleToNumber(string s) {
        long long ans = 0;
        for(auto ch : s) {
            ans = ans * 26 + ch - 'A' + 1;
        }
        return ans;
    }
};

```