# 字符串的排列  LCOF **
- 题目地址: [https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof)
- 执行时间: 156 ms
- 内存消耗: 17.6 MB
- 通过日期: 2020-04-28 16:00

## 题目内容
<p>输入一个字符串，打印出该字符串中字符的所有排列。</p>



<p>你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入：</strong>s = "abc"
<strong>输出：[</strong>"abc","acb","bac","bca","cab","cba"<strong>]</strong>
</pre>



<p><strong>限制：</strong></p>

<p><code>1 <= s 的长度 <= 8</code></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        vector<bool> vis(s.size(), false);
        string path;
        sort(s.begin(), s.end());
        backtrack(res, s, path, vis);
        return res;
    }
    void backtrack(vector<string> &res, string &s, string &path, vector<bool> &vis) {
        if(path.size() == s.size()) res.push_back(path);

        for(int i = 0; i < s.size(); i++) {
            if(vis[i] == true || (i > 0 && s[i] == s[i-1] && vis[i-1] == false)) continue;
            path.push_back(s[i]);
            vis[i] = true;
            backtrack(res, s, path, vis);
            vis[i] = false;
            path.pop_back();
        }
    }
};

```