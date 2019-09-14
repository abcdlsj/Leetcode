# Search Insert Position :star:
- 题目地址: [https://leetcode-cn.com/problems/search-insert-position](https://leetcode-cn.com/problems/search-insert-position)
- 执行时间: 16 ms 
- 内存消耗: 8.8 MB
- 通过日期: 2019-08-27 21:18

## 题目内容
<p>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。</p>

<p>你可以假设数组中无重复元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,3,5,6], 5
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [1,3,5,6], 2
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> [1,3,5,6], 7
<strong>输出:</strong> 4
</pre>

<p><strong>示例 4:</strong></p>

<pre><strong>输入:</strong> [1,3,5,6], 0
<strong>输出:</strong> 0
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return 0;
        int ans;
        for(int i=0;i<n;i++)
        {
            if(target==nums[i]) return i;
            if(target<nums[0]) return 0;
            if(target>nums[i]) ans=i+1;
            if(target<nums[i]) return ans;
        }
        return n;
    }
};



```