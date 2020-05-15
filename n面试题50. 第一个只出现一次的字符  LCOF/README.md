# 第一个只出现一次的字符  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof)
- 执行时间: 196 ms
- 内存消耗: 11 MB
- 通过日期: 2020-04-06 13:38

## 题目内容
<p>在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。</p>

<p><strong>示例:</strong></p>

<pre>s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= s 的长度 <= 50000</code></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    char firstUniqChar(string s) {
        map<char, int> map;
        for(auto ch : s) {
            map[ch]++;
        }
        for(auto ch : s) {
            if(map[ch] == 1) return ch;
        }
        return ' ';
    }
};

```