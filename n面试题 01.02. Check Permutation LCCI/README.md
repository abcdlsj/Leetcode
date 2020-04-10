# Check Permutation LCCI *
- 题目地址: [https://leetcode-cn.com/problems/check-permutation-lcci](https://leetcode-cn.com/problems/check-permutation-lcci)
- 执行时间: 0 ms
- 内存消耗: 6.2 MB
- 通过日期: 2020-03-30 09:03

## 题目内容
<p>给定两个字符串 <code>s1</code> 和 <code>s2</code>，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> <code>s1</code> = "abc", <code>s2</code> = "bca"
<strong>输出:</strong> true 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> <code>s1</code> = "abc", <code>s2</code> = "bad"
<strong>输出:</strong> false
</pre>

<p><strong>说明：</strong></p>

<ul>
	<li><code>0 <= len(s1) <= 100 </code></li>
	<li><code>0 <= len(s2) <= 100 </code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> cnt(200, 0);
        if(s1.size() != s2.size()) return false;
        for(int i = 0; i < s1.size(); i++) {
            cnt[s1[i]] ++;
            cnt[s2[i]] --;
        }
        for(auto i : cnt) {
            if(i != 0) return false; 
        }
        return true;
    }
};

```