# Minimum Window Substring ***
- 题目地址: [https://leetcode-cn.com/problems/minimum-window-substring](https://leetcode-cn.com/problems/minimum-window-substring)
- 执行时间: 64 ms
- 内存消耗: 7.8 MB
- 通过日期: 2020-04-21 15:37

## 题目内容
<p>给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入: S</strong> = "ADOBECODEBANC", <strong>T</strong> = "ABC"
<strong>输出:</strong> "BANC"</pre>

<p><strong>说明：</strong></p>

<ul>
	<li>如果 S 中不存这样的子串，则返回空字符串 <code>""</code>。</li>
	<li>如果 S 中存在这样的子串，我们保证它是唯一的答案。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, match = 0, start = 0, minlen = INT_MAX;
        unordered_map<char, int> windows, needs;
        for(auto c : t) needs[c]++;
        while(right < s.size()) {
            char cright = s[right];
            if(needs.count(cright)) {
                windows[cright]++;
                if(windows[cright] == needs[cright]) match++;
            }
            while(match == needs.size()) {
                if(right - left + 1 < minlen) {
                    start = left;
                    minlen = right - left + 1;
                }
                char cleft = s[left];
                if(needs.count(cleft)) {
                    windows[cleft]--;
                    if(windows[cleft] < needs[cleft]) match--;
                }
                left++;
            }
            right++;
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};

```