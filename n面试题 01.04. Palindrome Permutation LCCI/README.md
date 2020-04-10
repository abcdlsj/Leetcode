# Palindrome Permutation LCCI *
- 题目地址: [https://leetcode-cn.com/problems/palindrome-permutation-lcci](https://leetcode-cn.com/problems/palindrome-permutation-lcci)
- 执行时间: 4 ms
- 内存消耗: 6.5 MB
- 通过日期: 2020-03-30 09:44

## 题目内容
<p>给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。</p>

<p>回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。</p>

<p>回文串不一定是字典当中的单词。</p>



<p><strong>示例1：</strong></p>

<pre><strong>输入："</strong>tactcoa"
<strong>输出：</strong>true（排列有"tacocat"、"atcocta"，等等）
</pre>




## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.length() == 1 || s.length() == 0) return true;
        vector<int> cnt(200, 0);
        int num = 0, odd = 0, even = 0;
        for(auto i : s) {
            if(cnt[i] == 0) num++;
            cnt[i] ++;
        }
        for(int i = 0; i < cnt.size(); i ++) {
            if (cnt[i] % 2 == 0 && cnt[i] != 0) even ++;
            if (cnt[i] % 2 == 1 && cnt[i] != 0) odd ++;
        }
        if(odd == 1 && even + odd == num) return true;
        else if (even == num) return true;
        return false;
    }
};

```