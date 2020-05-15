# Add Strings *
- 题目地址: [https://leetcode-cn.com/problems/add-strings](https://leetcode-cn.com/problems/add-strings)
- 执行时间: 4 ms
- 内存消耗: 6.9 MB
- 通过日期: 2020-05-11 20:28

## 题目内容
<p>给定两个字符串形式的非负整数 <code>num1</code> 和<code>num2</code> ，计算它们的和。</p>

<p><strong>注意：</strong></p>

<ol>
	<li><code>num1</code> 和<code>num2</code> 的长度都小于 5100.</li>
	<li><code>num1</code> 和<code>num2</code> 都只包含数字 <code>0-9</code>.</li>
	<li><code>num1</code> 和<code>num2</code> 都不包含任何前导零。</li>
	<li><strong>你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。</strong></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string addStrings(string num1, string num2) {
        string str = "";
        int cur = 0, i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 || j >= 0 || cur != 0) {
            if(i >= 0) cur += num1[i--] - '0';
            if(j >= 0) cur += num2[j--] - '0';
            str += cur % 10 + '0';
            cur /= 10;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

```