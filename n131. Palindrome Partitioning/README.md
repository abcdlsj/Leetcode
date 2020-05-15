# Palindrome Partitioning **
- 题目地址: [https://leetcode-cn.com/problems/palindrome-partitioning](https://leetcode-cn.com/problems/palindrome-partitioning)
- 执行时间: 248 ms
- 内存消耗: 26.7 MB
- 通过日期: 2020-05-12 18:57

## 题目内容
<p>给定一个字符串 <em>s</em>，将<em> s </em>分割成一些子串，使每个子串都是回文串。</p>

<p>返回 <em>s</em> 所有可能的分割方案。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> "aab"
<strong>输出:</strong>
[
  ["aa","b"],
  ["a","a","b"]
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(res, path, s, 0);
        return res;
    }
    void backtrack(vector<vector<string>> &res, vector<string> &path, const string &s, int start) {
        if(start == s.size()) res.push_back(path);

        for(int i = start; i < s.size(); i++) {
            string ss = s.substr(start, i - start + 1);
            if(ispa(ss)) {
                path.push_back(ss);
                backtrack(res, path, s, i + 1);
                path.pop_back();
            } else {
                continue;
            }
        }
    }
    bool ispa(string s) {
        return s == string(s.rbegin(), s.rend());
    }
};

```