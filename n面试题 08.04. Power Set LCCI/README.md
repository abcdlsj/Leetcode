# Power Set LCCI **
- 题目地址: [https://leetcode-cn.com/problems/power-set-lcci](https://leetcode-cn.com/problems/power-set-lcci)
- 执行时间: 0 ms
- 内存消耗: 7.3 MB
- 通过日期: 2020-05-15 08:24

## 题目内容
<p>幂集。编写一种方法，返回某集合的所有子集。集合中<strong>不包含重复的元素</strong>。</p>

<p>说明：解集不能包含重复的子集。</p>

<p><strong>示例:</strong></p>

<pre><strong> 输入</strong>： nums = [1,2,3]
<strong> 输出</strong>：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;

        backtrack(res, path, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, const vector<int> &nums, int start) {
        res.push_back(path);

        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(res, path, nums, i + 1);
            path.pop_back();
        }
    }
};

```