# Palindrome Partitioning **
- 题目地址: [https://leetcode-cn.com/problems/palindrome-partitioning](https://leetcode-cn.com/problems/palindrome-partitioning)
- 执行时间: 172 ms
- 内存消耗: 15.6 MB
- 通过日期: 2020-04-08 20:44

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
        if(s.size() == 0) return res;
        backtrack(res, path, 0, s);
        return res;
    }
    void backtrack(vector<vector<string>> &res, vector<string> &path, int start, const string &s) {
        if(start >= s.size()) {
            res.push_back(path);
            return;
        }
        string tmp = "";
        for(int i = start; i < s.size(); i++) {
            tmp.push_back(s[i]);
            if(ispalindrome(tmp)) {
                path.push_back(tmp);
                backtrack(res, path, i + 1, s);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(const string &s) {
        return s == string(s.rbegin(), s.rend());
    }
};

```