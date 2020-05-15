# Subsets II **
- 题目地址: [https://leetcode-cn.com/problems/subsets-ii](https://leetcode-cn.com/problems/subsets-ii)
- 执行时间: 8 ms
- 内存消耗: 7.7 MB
- 通过日期: 2020-04-05 13:50

## 题目内容
<p>给定一个可能包含重复元素的整数数组 <em><strong>nums</strong></em>，返回该数组所有可能的子集（幂集）。</p>

<p><strong>说明：</strong>解集不能包含重复的子集。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,2,2]
<strong>输出:</strong>
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> vis(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(res, path, nums, vis, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> path, vector<int> nums, vector<bool> vis, int start) {
        res.push_back(path);
        for(int i = start; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == false) continue;
            path.push_back(nums[i]);
            vis[i] = true;
            backtrack(res, path, nums, vis, i + 1);
            vis[i] = false;
            path.pop_back();
        }
    }
};

```