# Contiguous Sequence LCCI *
- 题目地址: [https://leetcode-cn.com/problems/contiguous-sequence-lcci](https://leetcode-cn.com/problems/contiguous-sequence-lcci)
- 执行时间: 16 ms
- 内存消耗: 12.9 MB
- 通过日期: 2020-04-03 19:42

## 题目内容
<p>给定一个整数数组（有正数有负数），找出总和最大的连续数列，并返回总和。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong> [-2,1,-3,4,-1,2,1,-5,4]
<strong>输出：</strong> 6
<strong>解释：</strong> 连续子数组 [4,-1,2,1] 的和最大，为 6。
</pre>

<p><strong>进阶：</strong></p>

<p>如果你已经实现复杂度为 O(<em>n</em>) 的解法，尝试使用更为精妙的分治法求解。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxarray(nums, 0, nums.size() - 1);
    }
    int maxarray(vector<int> &nums, int left, int right) {
        if(left == right) return nums[left];
        int mid = left + (right - left) / 2;
        int leftsum = maxarray(nums, left, mid);
        int rightsum = maxarray(nums, mid + 1, right);
        int crosssum = maxcross(nums, left, right, mid);
        int res = max(max(leftsum, rightsum), crosssum);
        return res;
    }
    int maxcross(vector<int> &nums, int left, int right, int mid) {
        int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;
        for(int i = mid; i >= left; i--) {
            sum += nums[i];
            leftsum = max(leftsum, sum);
        }
        sum = 0;
        for(int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightsum = max(rightsum, sum);
        }
        return leftsum + rightsum;
    }
};

```