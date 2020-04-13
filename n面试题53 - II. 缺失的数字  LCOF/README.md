# 缺失的数字  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof)
- 执行时间: 72 ms
- 内存消耗: 17 MB
- 通过日期: 2020-04-13 18:17

## 题目内容
<p>一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [0,1,3]
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [0,1,2,3,4,5,6,7,9]
<strong>输出:</strong> 8</pre>



<p><strong>限制：</strong></p>

<p><code>1 <= 数组长度 <= 10000</code></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] != mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

```