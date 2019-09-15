# Maximum Subarray *
- 题目地址: [https://leetcode-cn.com/problems/maximum-subarray](https://leetcode-cn.com/problems/maximum-subarray)
- 执行时间: 8 ms 
- 内存消耗: 9.3 MB
- 通过日期: 2019-09-15 09:42

## 题目内容
<p>给定一个整数数组 <code>nums</code> ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [-2,1,-3,4,-1,2,1,-5,4],
<strong>输出:</strong> 6
<strong>解释:</strong> 连续子数组 [4,-1,2,1] 的和最大，为 6。
</pre>

<p><strong>进阶:</strong></p>

<p>如果你已经实现复杂度为 O(<em>n</em>) 的解法，尝试使用更为精妙的分治法求解。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> cnt(nums);
        int maxn = nums[0];
        for(int i=1;i<nums.size();++i){
            cnt[i] = max(cnt[i-1]+nums[i],nums[i]);
            
            if(maxn<cnt[i])
                maxn = cnt[i];
        }
        return maxn;
     }
};

```