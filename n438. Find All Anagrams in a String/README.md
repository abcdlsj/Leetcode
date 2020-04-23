# Find All Anagrams in a String **
- 题目地址: [https://leetcode-cn.com/problems/find-all-anagrams-in-a-string](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string)
- 执行时间: 56 ms
- 内存消耗: 8.9 MB
- 通过日期: 2020-04-21 16:37

## 题目内容
<p>给定一个字符串 <strong>s </strong>和一个非空字符串 <strong>p</strong>，找到 <strong>s </strong>中所有是 <strong>p </strong>的字母异位词的子串，返回这些子串的起始索引。</p>

<p>字符串只包含小写英文字母，并且字符串 <strong>s </strong>和 <strong>p </strong>的长度都不超过 20100。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>字母异位词指字母相同，但排列不同的字符串。</li>
	<li>不考虑答案输出的顺序。</li>
</ul>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong>
s: "cbaebabacd" p: "abc"

<strong>输出:</strong>
[0, 6]

<strong>解释:</strong>
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
</pre>

<p><strong> 示例 2:</strong></p>

<pre>
<strong>输入:</strong>
s: "abab" p: "ab"

<strong>输出:</strong>
[0, 1, 2]

<strong>解释:</strong>
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0, match = 0;
        vector<int> res;
        unordered_map<char, int> window, needs;
        for(auto c : p) needs[c]++;
        while(right < s.size()) {
            char cright = s[right];
            if(needs.count(cright)) {
                window[cright]++;
                if(window[cright] == needs[cright]) match++;
            }
            while(match == needs.size()) {
                if(right - left + 1 == p.size()) res.push_back(left);
                char cleft = s[left];
                if(needs.count(cleft)) {
                    window[cleft]--;
                    if(window[cleft] < needs[cleft]) match--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};

```