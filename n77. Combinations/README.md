# Combinations **
- 题目地址: [https://leetcode-cn.com/problems/combinations](https://leetcode-cn.com/problems/combinations)
- 执行时间: 8 ms
- 内存消耗: 9.2 MB
- 通过日期: 2020-04-01 14:23

## 题目内容
<p>给定两个整数 <em>n</em> 和 <em>k</em>，返回 1 ... <em>n </em>中所有可能的 <em>k</em> 个数的组合。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> n = 4, k = 2
<strong>输出:</strong>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, n, k, 1);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, int n, int k, int start) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        for(int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrack(res, path, n, k, i+1);
            path.pop_back();
        }
    }
};

```