# Find Peak Element **
- 题目地址: [https://leetcode-cn.com/problems/find-peak-element](https://leetcode-cn.com/problems/find-peak-element)
- 执行时间: 4 ms
- 内存消耗: 11.8 MB
- 通过日期: 2020-03-11 15:27

## 题目内容
<p>峰值元素是指其值大于左右相邻值的元素。</p>

<p>给定一个输入数组 <code>nums</code>，其中 <code>nums[i] ≠ nums[i+1]</code>，找到峰值元素并返回其索引。</p>

<p>数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。</p>

<p>你可以假设 <code>nums[-1] = nums[n] = -∞</code>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <strong>nums</strong> = <code>[1,2,3,1]</code>
<strong>输出:</strong> 2
<strong>解释: </strong>3 是峰值元素，你的函数应该返回其索引 2。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <strong>nums</strong> = <code>[</code>1,2,1,3,5,6,4]
<strong>输出:</strong> 1 或 5 
<strong>解释:</strong> 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
</pre>

<p><strong>说明:</strong></p>

<p>你的解法应该是 <em>O</em>(<em>logN</em>)<em> </em>时间复杂度的。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int binarysearch(vector<int> nums, int left, int right) {
        if(left >= right) return left;
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[mid + 1])
            return binarysearch(nums, left, mid);
        else
            return binarysearch(nums, mid + 1, right);
    }
    int findPeakElement(vector<int>& nums) {
        return binarysearch(nums, 0, nums.size() - 1);
    }
};

```