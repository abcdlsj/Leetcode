# Generate Parentheses **
- 题目地址: [https://leetcode-cn.com/problems/generate-parentheses](https://leetcode-cn.com/problems/generate-parentheses)
- 执行时间: 12 ms
- 内存消耗: 16.7 MB
- 通过日期: 2020-04-09 09:13

## 题目内容
<p>数字 <em>n</em> 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 <strong>有效的 </strong>括号组合。</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }

    void dfs(vector<string> &res, const string &path, int left, int right, int n) {
        if(left > n || right > n || right > left) return;
        if(left == n && right == n) {
            res.push_back(path);
            return;
        } 
        dfs(res, path + '(', left + 1, right, n);
        dfs(res, path + ')', left, right + 1, n);
    }
};


```