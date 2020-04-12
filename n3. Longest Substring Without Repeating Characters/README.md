# Longest Substring Without Repeating Characters **
- 题目地址: [https://leetcode-cn.com/problems/longest-substring-without-repeating-characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters)
- 执行时间: 96 ms
- 内存消耗: 8.6 MB
- 通过日期: 2020-04-12 19:49

## 题目内容
<p>给定一个字符串，请你找出其中不含有重复字符的 <strong>最长子串 </strong>的长度。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>"abcabcbb"
<strong>输出: </strong>3 
<strong>解释:</strong> 因为无重复字符的最长子串是 <code>"abc"，所以其</code>长度为 3。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>"bbbbb"
<strong>输出: </strong>1
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"b"</code>，所以其长度为 1。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入: </strong>"pwwkew"
<strong>输出: </strong>3
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"wke"</code>，所以其长度为 3。
     请注意，你的答案必须是 <strong>子串 </strong>的长度，<code>"pwke"</code> 是一个<em>子序列，</em>不是子串。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> map;
        int start = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(map.find(s[i]) != map.end()) {
                start = max(map[s[i]] + 1, start);
            }
            ans = max(ans, i - start + 1);
            map[s[i]] = i;
        }
        return ans;
    }
};

```