# Longest Palindromic Substring **
- 题目地址: [https://leetcode-cn.com/problems/longest-palindromic-substring](https://leetcode-cn.com/problems/longest-palindromic-substring)
- 执行时间: 96 ms
- 内存消耗: 102 MB
- 通过日期: 2020-03-24 21:12

## 题目内容
<p>给定一个字符串 <code>s</code>，找到 <code>s</code> 中最长的回文子串。你可以假设 <code>s</code> 的最大长度为 1000。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> "babad"
<strong>输出:</strong> "bab"
<strong>注意:</strong> "aba" 也是一个有效答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> "cbbd"
<strong>输出:</strong> "bb"
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start) {
                start = i - (len - 1) / 2; // a b a [c] c a b a
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    int expand(string s, int left, int right) {
        int le = left, ri = right;
        while(le >= 0 && ri < s.size() && s[le] == s[ri]) {
            le --;
            ri ++;
        }
        return ri - le - 1;
    }
};

```