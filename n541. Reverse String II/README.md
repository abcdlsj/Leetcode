# Reverse String II *
- 题目地址: [https://leetcode-cn.com/problems/reverse-string-ii](https://leetcode-cn.com/problems/reverse-string-ii)
- 执行时间: 4 ms
- 内存消耗: 7.4 MB
- 通过日期: 2020-05-11 11:19

## 题目内容
<p>给定一个字符串 <code>s</code> 和一个整数 <code>k</code>，你需要对从字符串开头算起的每隔 <code>2k</code> 个字符的前 <code>k</code> 个字符进行反转。</p>

<ul>
	<li>如果剩余字符少于 <code>k</code> 个，则将剩余字符全部反转。</li>
	<li>如果剩余字符小于 <code>2k</code> 但大于或等于 <code>k</code> 个，则反转前 <code>k</code> 个字符，其余字符保持原样。</li>
</ul>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> s = "abcdefg", k = 2
<strong>输出:</strong> "bacdfeg"
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li>该字符串只包含小写英文字母。</li>
	<li>给定字符串的长度和 <code>k</code> 在 <code>[1, 10000]</code> 范围内。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (s.size() - i < k) {
                reverse(s.begin() + i, s.end());
            } else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};

```