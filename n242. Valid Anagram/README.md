# Valid Anagram *
- 题目地址: [https://leetcode-cn.com/problems/valid-anagram](https://leetcode-cn.com/problems/valid-anagram)
- 执行时间: 16 ms
- 内存消耗: 9.8 MB
- 通过日期: 2020-03-01 20:52

## 题目内容
<p>给定两个字符串 <em>s</em> 和 <em>t</em> ，编写一个函数来判断 <em>t</em> 是否是 <em>s</em> 的字母异位词。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <em>s</em> = "anagram", <em>t</em> = "nagaram"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <em>s</em> = "rat", <em>t</em> = "car"
<strong>输出: </strong>false</pre>

<p><strong>说明:</strong><br>
你可以假设字符串只包含小写字母。</p>

<p><strong>进阶:</strong><br>
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ss(26,0);
        vector<int> tt(26,0);
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++) {
            ss[s[i] - 'a'] ++;
            tt[t[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; i++) {
            if(ss[i] != tt[i]) return false;
        }
        return true;
    }
};

```