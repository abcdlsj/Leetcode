# Combination Sum **
- 题目地址: [https://leetcode-cn.com/problems/combination-sum](https://leetcode-cn.com/problems/combination-sum)
- 执行时间: 12 ms
- 内存消耗: 7.7 MB
- 通过日期: 2020-04-23 21:58

## 题目内容
<p>给定一个<strong>无重复元素</strong>的数组 <code>candidates</code> 和一个目标数 <code>target</code> ，找出 <code>candidates</code> 中所有可以使数字和为 <code>target</code> 的组合。</p>

<p><code>candidates</code> 中的数字可以无限制重复被选取。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>所有数字（包括 <code>target</code>）都是正整数。</li>
	<li>解集不能包含重复的组合。 </li>
</ul>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> candidates = <code>[2,3,6,7], </code>target = <code>7</code>,
<strong>所求解集为:</strong>
[
  [7],
  [2,2,3]
]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> candidates = [2,3,5]<code>, </code>target = 8,
<strong>所求解集为:</strong>
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            path.push_back(candidates[i]);
            backtrack(res, path, candidates, target, i, sum + candidates[i]);
            path.pop_back();
        }
    }
 };

```