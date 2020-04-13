# 连续子数组的最大和  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof)
- 执行时间: 88 ms
- 内存消耗: 23.7 MB
- 通过日期: 2020-04-13 15:24

## 题目内容
<p>输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。</p>

<p>要求时间复杂度为O(n)。</p>



<p><strong>示例1:</strong></p>

<pre><strong>输入:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>输出:</strong> 6
<strong>解释:</strong> 连续子数组 [4,-1,2,1] 的和最大，为 6。</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10^5</code></li>
	<li><code>-100 <= arr[i] <= 100</code></li>
</ul>

<p>注意：本题与主站 53 题相同：<a href="https://leetcode-cn.com/problems/maximum-subarray/">https://leetcode-cn.com/problems/maximum-subarray/</a></p>




## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        int maxnum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + dp[i], dp[i]);
            maxnum = max(maxnum, dp[i]);
        }
        return maxnum;
    }
};

```