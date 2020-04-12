# 3Sum **
- 题目地址: [https://leetcode-cn.com/problems/3sum](https://leetcode-cn.com/problems/3sum)
- 执行时间: 132 ms
- 内存消耗: 18.9 MB
- 通过日期: 2020-03-19 20:58

## 题目内容
<p>给你一个包含 <em>n</em> 个整数的数组 <code>nums</code>，判断 <code>nums</code> 中是否存在三个元素 <em>a，b，c ，</em>使得 <em>a + b + c = </em>0 ？请你找出所有满足条件且不重复的三元组。</p>

<p><strong>注意：</strong>答案中不可以包含重复的三元组。</p>



<p><strong>示例：</strong></p>

<pre>给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int c = 0; c < nums.size() - 2 && nums.size() >= 3; c++) {
            int le = c + 1, ri = nums.size() - 1;
            while(le < ri) {
                if(nums[c] + nums[le] + nums[ri] == 0) {
                    res.insert({nums[c], nums[le], nums[ri]});
                    ri--;le++;
                    while(le < ri && nums[ri] == nums[ri+1]) ri--;
                    while(le < ri && nums[le] == nums[le-1]) le++;
                }
                else if(nums[c] + nums[le] + nums[ri] < 0)
                    le++;
                else 
                    ri--;
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};

```