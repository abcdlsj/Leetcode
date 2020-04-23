# Combination Sum II **
- 题目地址: [https://leetcode-cn.com/problems/combination-sum-ii](https://leetcode-cn.com/problems/combination-sum-ii)
- 执行时间: 12 ms
- 内存消耗: 7.1 MB
- 通过日期: 2020-04-23 21:37

## 题目内容
<p>给定一个数组 <code>candidates</code> 和一个目标数 <code>target</code> ，找出 <code>candidates</code> 中所有可以使数字和为 <code>target</code> 的组合。</p>

<p><code>candidates</code> 中的每个数字在每个组合中只能使用一次。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>所有数字（包括目标数）都是正整数。</li>
	<li>解集不能包含重复的组合。 </li>
</ul>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> candidates = <code>[10,1,2,7,6,1,5]</code>, target = <code>8</code>,
<strong>所求解集为:</strong>
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> candidates = [2,5,2,1,2], target = 5,
<strong>所求解集为:</strong>
[
  [1,2,2],
  [5]
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, candidates, target, 0, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates, int target, int start, int sum) {
        if(sum > target) return;
        if(sum == target) res.push_back(path);
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtrack(res, path, candidates, target, i + 1, sum + candidates[i]);
            path.pop_back();
        }
    }
};

```