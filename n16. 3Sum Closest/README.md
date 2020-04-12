# 3Sum Closest **
- 题目地址: [https://leetcode-cn.com/problems/3sum-closest](https://leetcode-cn.com/problems/3sum-closest)
- 执行时间: 28 ms
- 内存消耗: 6.6 MB
- 通过日期: 2020-04-01 00:03

## 题目内容
<p>给定一个包括 <em>n</em> 个整数的数组 <code>nums</code><em> </em>和 一个目标值 <code>target</code>。找出 <code>nums</code><em> </em>中的三个整数，使得它们的和与 <code>target</code> 最接近。返回这三个数的和。假定每组输入只存在唯一答案。</p>

<pre>例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return accumulate(nums.begin(), nums.end(), 0);
        int res, mingap = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                if(abs(nums[left] + nums[right] + nums[i] - target) < mingap) {
                    mingap = abs(nums[left] + nums[right] + nums[i] - target);
                    res = nums[left] + nums[right] + nums[i];
                } 
                if(nums[left] + nums[right] + nums[i] > target) right --;
                else left ++;
            }   
        }
        return res;
    }
};

```