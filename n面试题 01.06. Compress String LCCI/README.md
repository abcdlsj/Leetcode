# Compress String LCCI *
- 题目地址: [https://leetcode-cn.com/problems/compress-string-lcci](https://leetcode-cn.com/problems/compress-string-lcci)
- 执行时间: 28 ms
- 内存消耗: 7.3 MB
- 通过日期: 2020-03-30 10:02

## 题目内容
<p>字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串<code>aabcccccaaa</code>会变为<code>a2b1c5a3</code>。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。</p>

<p> <strong>示例1:</strong></p>

<pre>
<strong> 输入</strong>："aabcccccaaa"
<strong> 输出</strong>："a2b1c5a3"
</pre>

<p> <strong>示例2:</strong></p>

<pre>
<strong> 输入</strong>："abbccd"
<strong> 输出</strong>："abbccd"
<strong> 解释</strong>："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
</pre>

<p><strong>提示：</strong></p>

<ol>
<li>字符串长度在[0, 50000]范围内。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string compressString(string S) {
        string res;
        int i = 0, j = 0;
        while(i < S.length() && j < S.length()) {
            while(S[i] == S[j]) j++;
            res += S[i];
            res += to_string(j - i);
            i = j;
        }
        return S.length() <= res.length() ? S : res;
        //return res;
    }
};

```