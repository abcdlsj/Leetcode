# Binary Search *
- 题目地址: [https://leetcode-cn.com/problems/binary-search](https://leetcode-cn.com/problems/binary-search)
- 执行时间: 68 ms
- 内存消耗: 10.8 MB
- 通过日期: 2019-08-26 10:33

## 题目内容
<p>给定一个 <code>n</code> 个元素有序的（升序）整型数组 <code>nums</code> 和一个目标值 <code>target</code>  ，写一个函数搜索 <code>nums</code> 中的 <code>target</code>，如果目标值存在返回下标，否则返回 <code>-1</code>。</p>

<p><br>
<strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>输出:</strong> 4
<strong>解释:</strong> 9 出现在 <code>nums</code> 中并且下标为 4
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>输出:</strong> -1
<strong>解释:</strong> 2 不存在 <code>nums</code> 中因此返回 -1
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li>你可以假设 <code>nums</code> 中的所有元素是不重复的。</li>
	<li><code>n</code> 将在 <code>[1, 10000]</code>之间。</li>
	<li><code>nums</code> 的每个元素都将在 <code>[-9999, 9999]</code>之间。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int end=n-1,start=0,mid;
        while(start<=end)
        {
            mid=(end-start)/2+start;
            if(target>nums[mid])
                start=mid+1;
            if(target<nums[mid])
                end=mid-1;
            if(target==nums[mid])
                return mid;
        }
        return -1;
    }
};

```