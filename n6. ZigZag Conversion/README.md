# ZigZag Conversion **
- 题目地址: [https://leetcode-cn.com/problems/zigzag-conversion](https://leetcode-cn.com/problems/zigzag-conversion)
- 执行时间: 20 ms
- 内存消耗: 10.4 MB
- 通过日期: 2020-05-06 14:03

## 题目内容
<p>将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。</p>

<p>比如输入字符串为 <code>"LEETCODEISHIRING"</code> 行数为 3 时，排列如下：</p>

<pre>L   C   I   R
E T O E S I I G
E   D   H   N
</pre>

<p>之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：<code>"LCIRETOESIIGEDHN"</code>。</p>

<p>请你实现这个将字符串进行指定行数变换的函数：</p>

<pre>string convert(string s, int numRows);</pre>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> s = "LEETCODEISHIRING", numRows = 3
<strong>输出:</strong> "LCIRETOESIIGEDHN"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> s = "LEETCODEISHIRING", numRows = 4
<strong>输出:</strong> "LDREOEIIECIHNTSG"
<strong>解释:</strong>

L     D     R
E   O E   I I
E C   I H   N
T     S     G</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows);
        string res;
        if(s.empty() || numRows < 1) return res;
        if(numRows == 1) return s;
        int ans = 0, cur = 0;
        for(int i = 0; i < s.size(); i++) {
            ans = i / (numRows - 1), cur = i % (numRows - 1);
            if(ans % 2 == 0) {
                strs[cur].push_back(s[i]);
            } else {
                strs[numRows - cur - 1].push_back(s[i]);
            }
        }

        for(int i = 0; i < strs.size(); i++) {
            res += strs[i];
        }
        return res;
    }
};

```