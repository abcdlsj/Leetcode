# Permutations **
- 题目地址: [https://leetcode-cn.com/problems/permutations](https://leetcode-cn.com/problems/permutations)
- 执行时间: 28 ms
- 内存消耗: 8.8 MB
- 通过日期: 2020-04-05 10:31

## 题目内容
<p>给定一个<strong> 没有重复</strong> 数字的序列，返回其所有可能的全排列。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,2,3]
<strong>输出:</strong>
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> vis(nums.size(), false);
        backtrack(res, path, nums, vis);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> path, vector<int> nums, vector<bool> vis) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(vis[i] == true) continue;
            path.push_back(nums[i]);
            vis[i] = true;
            backtrack(res, path, nums, vis);
            path.pop_back();
            vis[i] = false;
        }
    }
};

```