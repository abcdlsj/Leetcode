# Bracket LCCI **
- 题目地址: [https://leetcode-cn.com/problems/bracket-lcci](https://leetcode-cn.com/problems/bracket-lcci)
- 执行时间: 12 ms
- 内存消耗: 19.8 MB
- 通过日期: 2020-05-15 08:20

## 题目内容
<p>括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。</p>

<p>说明：解集不能包含重复的子集。</p>

<p>例如，给出 n = 3，生成结果为：</p>

<pre>
[
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
        string path;
        backtrack(res, path, 0, 0, n);
        return res;
    }
    void backtrack(vector<string> &res, const string &path, int left, int right, int n) {
        if(right > left || left > n || right > n) return;

        if(right == left && left == n) {
            res.push_back(path);
        }

        backtrack(res, path + "(", left + 1, right, n);
        backtrack(res, path + ")", left, right + 1, n);
    }
};

```