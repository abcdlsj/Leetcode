# Construct K Palindrome Strings **
- 题目地址: [https://leetcode-cn.com/problems/construct-k-palindrome-strings](https://leetcode-cn.com/problems/construct-k-palindrome-strings)
- 执行时间: 68 ms
- 内存消耗: 12.1 MB
- 通过日期: 2020-04-04 22:58

## 题目内容
<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> 。请你用 <code>s</code> 字符串中 <strong>所有字符</strong> 构造 <code>k</code> 个非空 <strong>回文串</strong> 。</p>

<p>如果你可以用 <code>s</code> 中所有字符构造 <code>k</code> 个回文字符串，那么请你返回 <strong>True</strong> ，否则返回 <strong>False</strong> 。</p>



<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "annabelle", k = 2
<strong>输出：</strong>true
<strong>解释：</strong>可以用 s 中所有字符构造 2 个回文字符串。
一些可行的构造方案包括："anna" + "elble"，"anbna" + "elle"，"anellena" + "b"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode", k = 3
<strong>输出：</strong>false
<strong>解释：</strong>无法用 s 中所有字符构造 3 个回文串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "true", k = 4
<strong>输出：</strong>true
<strong>解释：</strong>唯一可行的方案是让 s 中每个字符单独构成一个字符串。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "yzyzyzyzyzyzyzy", k = 2
<strong>输出：</strong>true
<strong>解释：</strong>你只需要将所有的 z 放在一个字符串中，所有的 y 放在另一个字符串中。那么两个字符串都是回文串。
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>s = "cr", k = 7
<strong>输出：</strong>false
<strong>解释：</strong>我们没有足够的字符去构造 7 个回文串。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10^5</code></li>
	<li><code>s</code> 中所有字符都是小写英文字母。</li>
	<li><code>1 <= k <= 10^5</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return false;
        if(k == s.length()) return true;
        vector<int> cnt(26, 0);
        int t = 0;
        for(auto c : s) cnt[c - 'a'] ^= 1;
        for(auto c : cnt) {
            if(c % 2 == 1)  t++;
        }
        if(t > k) return false;
        return true;
    }
};

```