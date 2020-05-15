# Valid Palindrome *
- 题目地址: [https://leetcode-cn.com/problems/valid-palindrome](https://leetcode-cn.com/problems/valid-palindrome)
- 执行时间: 16 ms
- 内存消耗: 7.6 MB
- 通过日期: 2020-05-12 11:45

## 题目内容
<p>给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。</p>

<p><strong>说明：</strong>本题中，我们将空字符串定义为有效的回文串。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "A man, a plan, a canal: Panama"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "race a car"
<strong>输出:</strong> false
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto c : s) {
            if(isalnum(c)) str += tolower(c);
        }
        for(int i = 0; i < str.size() / 2; i++) {
            if(str[i] != str[str.size() - i - 1]) return false;
        }
        return true;
    }
};

```