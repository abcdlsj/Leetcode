# Combination Sum III **
- 题目地址: [https://leetcode-cn.com/problems/combination-sum-iii](https://leetcode-cn.com/problems/combination-sum-iii)
- 执行时间: 4 ms
- 内存消耗: 6.4 MB
- 通过日期: 2020-04-23 22:34

## 题目内容
<p>找出所有相加之和为 <em><strong>n</strong> </em>的 <strong><em>k </em></strong>个数的组合<strong><em>。</em></strong>组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>所有数字都是正整数。</li>
	<li>解集不能包含重复的组合。 </li>
</ul>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 7
<strong>输出:</strong> [[1,2,4]]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 9
<strong>输出:</strong> [[1,2,6], [1,3,5], [2,3,4]]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, 0, 1, k, n);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, int sum, int start, int k, int n) {
        if(sum > n) return;
        if(sum == n && path.size() == k) res.push_back(path);
        for(int i = start; i <= 9; i++) {
            path.push_back(i);
            backtrack(res, path, sum + i, i + 1, k, n);
            path.pop_back();
        }
    }
};

```