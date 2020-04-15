# 翻转单词顺序 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof)
- 执行时间: 32 ms
- 内存消耗: 8.9 MB
- 通过日期: 2020-04-14 21:40

## 题目内容
<p>输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> "<code>the sky is blue</code>"
<strong>输出: </strong>"<code>blue is sky the</code>"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> "  hello world!  "
<strong>输出: </strong>"world! hello"
<strong>解释: </strong>输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:</strong> "a good   example"
<strong>输出: </strong>"example good a"
<strong>解释: </strong>如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
</pre>



<p><strong>说明：</strong></p>

<ul>
	<li>无空格字符构成一个单词。</li>
	<li>输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。</li>
	<li>如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。</li>
</ul>

<p><strong>注意：</strong>本题与主站 151 题相同：<a href="https://leetcode-cn.com/problems/reverse-words-in-a-string/">https://leetcode-cn.com/problems/reverse-words-in-a-string/</a></p>

<p><strong>注意：</strong>此题对比原题有改动</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "", tmp;
        while(ss >> tmp) {
            ans.insert(0, tmp + " ");
        }
        return ans.size() ? string(ans.begin(), ans.end() - 1) : ans;
    }
};

```