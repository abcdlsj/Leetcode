# Subsets **
- 题目地址: [https://leetcode-cn.com/problems/subsets](https://leetcode-cn.com/problems/subsets)
- 执行时间: 4 ms
- 内存消耗: 9.4 MB
- 通过日期: 2020-02-29 16:33

## 题目内容
<p>给定一组<strong>不含重复元素</strong>的整数数组 <em>nums</em>，返回该数组所有可能的子集（幂集）。</p>

<p><strong>说明：</strong>解集不能包含重复的子集。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> nums = [1,2,3]
<strong>输出:</strong>
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> res;
        vector<int> cnt;

        int m = 0;

        while(m < (1 << n)){
            for(int i = 0; i < n; ++i){
                if((1 << i) & m) cnt.push_back(nums[i]);
            }
            res.push_back(cnt);
            cnt.clear();
            m ++;
        }
        return res;
    }
};

```