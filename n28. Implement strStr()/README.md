# Implement strStr() *
- 题目地址: [https://leetcode-cn.com/problems/implement-strstr](https://leetcode-cn.com/problems/implement-strstr)
- 执行时间: 8 ms
- 内存消耗: 6.7 MB
- 通过日期: 2020-03-30 09:33

## 题目内容
<p>实现 <a href="https://baike.baidu.com/item/strstr/811469" target="_blank">strStr()</a> 函数。</p>

<p>给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  <strong>-1</strong>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> haystack = "hello", needle = "ll"
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> haystack = "aaaaa", needle = "bba"
<strong>输出:</strong> -1
</pre>

<p><strong>说明:</strong></p>

<p>当 <code>needle</code> 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。</p>

<p>对于本题而言，当 <code>needle</code> 是空字符串时我们应当返回 0 。这与C语言的 <a href="https://baike.baidu.com/item/strstr/811469" target="_blank">strstr()</a> 以及 Java的 <a href="https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)" target="_blank">indexOf()</a> 定义相符。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if((n == 0 && m != 0)) return -1;
        if((m == 0 && n == 0) || (n != 0 && m == 0)) return 0;
        for(int i = 0; i < n - m + 1; i++) {
            if(haystack[i] != needle[0]) continue;
            int flag = 1;
            for(int j = 0; j < m; j++) {
                if(haystack[i + j] != needle[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) return i;
        }
        return -1;
    }
};

```