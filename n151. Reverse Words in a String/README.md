# Reverse Words in a String **
- 题目地址: [https://leetcode-cn.com/problems/reverse-words-in-a-string](https://leetcode-cn.com/problems/reverse-words-in-a-string)
- 执行时间: 8 ms
- 内存消耗: 7.5 MB
- 通过日期: 2020-04-25 14:46

## 题目内容
<p>给定一个字符串，逐个翻转字符串中的每个单词。</p>



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



<p><strong>进阶：</strong></p>

<p>请选用 C 语言的用户尝试使用 <em>O</em>(1) 额外空间复杂度的原地解法。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int cur = 0;
        for(int left = 0; left < s.size(); left++) {
            if(s[left] != ' ') {
                if(cur != 0) {
                    s[cur++] = ' ';
                }
            }
            int right = left;
            while(s[right] != ' ' && right < s.size()) {
                s[cur++] = s[right++];
            }
            reverse(s.begin() + cur - (right - left), s.begin() + cur);
            left = right;
        }
        s.erase(s.begin() + cur, s.end());
        return s;
    }
};

```