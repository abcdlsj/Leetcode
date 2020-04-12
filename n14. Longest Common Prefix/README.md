# Longest Common Prefix *
- 题目地址: [https://leetcode-cn.com/problems/longest-common-prefix](https://leetcode-cn.com/problems/longest-common-prefix)
- 执行时间: 8 ms
- 内存消耗: 7.3 MB
- 通过日期: 2020-03-24 17:45

## 题目内容
<p>编写一个函数来查找字符串数组中的最长公共前缀。</p>

<p>如果不存在公共前缀，返回空字符串 <code>""</code>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>["flower","flow","flight"]
<strong>输出:</strong> "fl"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>["dog","racecar","car"]
<strong>输出:</strong> ""
<strong>解释:</strong> 输入不存在公共前缀。
</pre>

<p><strong>说明:</strong></p>

<p>所有输入只包含小写字母 <code>a-z</code> 。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string res = strs[0];
        for(auto str : strs) {
            while(str.find(res, 0) == -1 || str.find(res, 0) != 0){
                res = res.substr(0, res.length() - 1);
            }
        }
        return res;
    }
};


```