# Longest Palindrome *
- 题目地址: [https://leetcode-cn.com/problems/longest-palindrome](https://leetcode-cn.com/problems/longest-palindrome)
- 执行时间: 0 ms
- 内存消耗: 8.2 MB
- 通过日期: 2020-03-19 21:26

## 题目内容
<p>给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。</p>

<p>在构造过程中，请注意区分大小写。比如 <code>"Aa"</code> 不能当做一个回文字符串。</p>

<p><strong>注意:</strong><br />
假设字符串的长度不会超过 1010。</p>

<p><strong>示例 1: </strong></p>

<pre>
输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0; //记录奇数的个数
        vector<int> cnt(128);
        for(auto c : s) cnt[c] ++;
        for(auto c : cnt) count += (c % 2);
        return count == 0 ? s.size(): (s.size() - count + 1);
    }
};

```