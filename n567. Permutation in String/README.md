# Permutation in String **
- 题目地址: [https://leetcode-cn.com/problems/permutation-in-string](https://leetcode-cn.com/problems/permutation-in-string)
- 执行时间: 640 ms
- 内存消耗: 15.7 MB
- 通过日期: 2020-05-11 20:15

## 题目内容
<p>给定两个字符串 <strong>s1</strong> 和 <strong>s2</strong>，写一个函数来判断 <strong>s2</strong> 是否包含 <strong>s1 </strong>的排列。</p>

<p>换句话说，第一个字符串的排列之一是第二个字符串的子串。</p>

<p><strong>示例1:</strong></p>

<pre>
<strong>输入: </strong>s1 = "ab" s2 = "eidbaooo"
<strong>输出: </strong>True
<strong>解释:</strong> s2 包含 s1 的排列之一 ("ba").
</pre>



<p><strong>示例2:</strong></p>

<pre>
<strong>输入: </strong>s1= "ab" s2 = "eidboaoo"
<strong>输出:</strong> False
</pre>



<p><strong>注意：</strong></p>

<ol>
	<li>输入的字符串只包含小写字母</li>
	<li>两个字符串的长度都在 [1, 10,000] 之间</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> cnt(26, 0);
        for(auto c : s1) cnt[c - 'a']++;
        for(int i = 0; i < s2.size() - s1.size() + 1; i++) {
            if(cnt[s2[i] - 'a'] != 0) {
                vector<int> cntc(cnt.begin(), cnt.end());
                for(int j = i + s1.size() - 1; j >= i; j--) {
                    if(cntc[s2[j] - 'a'] != 0) cntc[s2[j] - 'a']--;
                }
                if(accumulate(cntc.begin(), cntc.end(), 0) == 0) return true;
            }
        }
        return false;
    }
};

```