# Multiply Strings **
- 题目地址: [https://leetcode-cn.com/problems/multiply-strings](https://leetcode-cn.com/problems/multiply-strings)
- 执行时间: 8 ms
- 内存消耗: 6.7 MB
- 通过日期: 2020-05-11 21:13

## 题目内容
<p>给定两个以字符串形式表示的非负整数 <code>num1</code> 和 <code>num2</code>，返回 <code>num1</code> 和 <code>num2</code> 的乘积，它们的乘积也表示为字符串形式。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> num1 = "2", num2 = "3"
<strong>输出:</strong> "6"</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> num1 = "123", num2 = "456"
<strong>输出:</strong> "56088"</pre>

<p><strong>说明：</strong></p>

<ol>
	<li><code>num1</code> 和 <code>num2</code> 的长度小于110。</li>
	<li><code>num1</code> 和 <code>num2</code> 只包含数字 <code>0-9</code>。</li>
	<li><code>num1</code> 和 <code>num2</code> 均不以零开头，除非是数字 0 本身。</li>
	<li><strong>不能使用任何标准库的大数类型（比如 BigInteger）</strong>或<strong>直接将输入转换为整数来处理</strong>。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        int m = num1.size(), n = num2.size(), sum;
        vector<int> res(m + n, 0); string str;
        for(int i = num1.size() - 1; i >= 0; i--) {
            for(int j = num2.size() - 1; j >= 0; j--) {
                sum = res[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        for(int i = 0; i < res.size(); i++) {
            if(i == 0 && res[i] == 0) continue;
            str.push_back(res[i] + '0');
        }
        return str;
    }
};

```