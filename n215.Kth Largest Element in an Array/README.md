# Kth Largest Element in an Array 
- 题目地址: [https://leetcode-cn.com/problems/kth-largest-element-in-an-array](https://leetcode-cn.com/problems/kth-largest-element-in-an-array)
- 执行时间: 12 ms
- 内存消耗: 9.3 MB
- 通过日期: 2019-08-28 18:24

## 题目内容
<p>在未排序的数组中找到第 <strong>k</strong> 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>[3,2,1,5,6,4] 和</code> k = 2
<strong>输出:</strong> 5
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <code>[3,2,3,1,2,4,5,5,6] 和</code> k = 4
<strong>输出:</strong> 4</pre>

<p><strong>说明: </strong></p>

<p>你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto it:nums)
        {
            q.push(it);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};

```