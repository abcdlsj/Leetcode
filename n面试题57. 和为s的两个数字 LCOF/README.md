# 和为s的两个数字 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof](https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof)
- 执行时间: 472 ms
- 内存消耗: 100.6 MB
- 通过日期: 2020-04-14 12:29

## 题目内容
<p>输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,7,11,15], target = 9
<strong>输出：</strong>[2,7] 或者 [7,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [10,26,30,31,47,60], target = 40
<strong>输出：</strong>[10,30] 或者 [30,10]
</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>1 <= nums[i] <= 10^6</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, sum;
        while(left < right) {
            sum = nums[left] + nums[right];
            if(sum < target) {
                left++;
            } else if(sum > target){
                right--;
            } else {
                return {nums[left], nums[right]};
            }
        }
        return {};
    }
};

```