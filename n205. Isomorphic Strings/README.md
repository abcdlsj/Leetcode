# Isomorphic Strings *
- 题目地址: [https://leetcode-cn.com/problems/isomorphic-strings](https://leetcode-cn.com/problems/isomorphic-strings)
- 执行时间: 4 ms
- 内存消耗: 9.3 MB
- 通过日期: 2020-02-13 12:36

## 题目内容
<p>给定两个字符串 <em><strong>s </strong></em>和 <strong><em>t</em></strong>，判断它们是否是同构的。</p>

<p>如果 <em><strong>s </strong></em>中的字符可以被替换得到 <strong><em>t </em></strong>，那么这两个字符串是同构的。</p>

<p>所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"egg", </code><strong><em>t = </em></strong><code>"add"</code>
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"foo", </code><strong><em>t = </em></strong><code>"bar"</code>
<strong>输出:</strong> false</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"paper", </code><strong><em>t = </em></strong><code>"title"</code>
<strong>输出:</strong> true</pre>

<p><strong>说明:</strong><br>
你可以假设 <em><strong>s </strong></em>和 <strong><em>t </em></strong>具有相同的长度。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      char *sc[128]={0};
      char *tc[128]={0};
      for(int i = 0;i<s.size();++i){
        sc[s[i]]+=i+1;
        tc[t[i]]+=i+1;
        if(sc[s[i]]!=tc[t[i]]) return false;
      }
      return true;
    }
};

```