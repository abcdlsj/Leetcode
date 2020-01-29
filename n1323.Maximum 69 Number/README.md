# Maximum 69 Number *
- 题目地址: [https://leetcode-cn.com/problems/maximum-69-number](https://leetcode-cn.com/problems/maximum-69-number)
- 执行时间: 0 ms
- 内存消耗: 8.2 MB
- 通过日期: 2020-01-19 14:05

## 题目内容
<p>给你一个仅由数字 6 和 9 组成的正整数 <code>num</code>。</p>

<p>你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。</p>

<p>请返回你可以得到的最大数字。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 9669
<strong>输出：</strong>9969
<strong>解释：</strong>
改变第一位数字可以得到 6669 。
改变第二位数字可以得到 9969 。
改变第三位数字可以得到 9699 。
改变第四位数字可以得到 9666 。
其中最大的数字是 9969 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 9996
<strong>输出：</strong>9999
<strong>解释：</strong>将最后一位从 6 变到 9，其结果 9999 是最大的数。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 9999
<strong>输出：</strong>9999
<strong>解释：</strong>无需改变就已经是最大的数字了。</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= num <= 10^4</code></li>
	<li><code>num</code> 每一位上的数字都是 6 或者 9 。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }

        int res = stoi(s);
        return res;
    }
};

```