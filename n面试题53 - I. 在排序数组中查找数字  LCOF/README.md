# 在排序数组中查找数字  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof)
- 执行时间: 16 ms
- 内存消耗: 13.3 MB
- 通过日期: 2020-04-13 17:50

## 题目内容
<p>统计一个数字在排序数组中出现的次数。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [<code>5,7,7,8,8,10]</code>, target = 8
<strong>输出:</strong> 2</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = [<code>5,7,7,8,8,10]</code>, target = 6
<strong>输出:</strong> 0</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= 数组长度 <= 50000</code></p>



<p><strong>注意：</strong>本题与主站 34 题相同（仅返回值不同）：<a href="https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/">https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return binarysearch(nums, target + 0.5) - binarysearch(nums, target - 0.5);
    }
    int binarysearch(vector<int>& nums, double target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target > nums[mid]) left = mid + 1;
            if(target < nums[mid]) right = mid - 1;
        }
        return left;
    } 
};

```