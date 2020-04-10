# Find the Duplicate Number **
- 题目地址: [https://leetcode-cn.com/problems/find-the-duplicate-number](https://leetcode-cn.com/problems/find-the-duplicate-number)
- 执行时间: 12 ms
- 内存消耗: 12.5 MB
- 通过日期: 2020-03-23 21:25

## 题目内容
<p>给定一个包含 <em>n</em> + 1 个整数的数组 <em>nums</em>，其数字都在 1 到 <em>n </em>之间（包括 1 和 <em>n</em>），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>[1,3,4,2,2]</code>
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [3,1,3,4,2]
<strong>输出:</strong> 3
</pre>

<p><strong>说明：</strong></p>

<ol>
	<li><strong>不能</strong>更改原数组（假设数组是只读的）。</li>
	<li>只能使用额外的 <em>O</em>(1) 的空间。</li>
	<li>时间复杂度小于 <em>O</em>(<em>n</em><sup>2</sup>) 。</li>
	<li>数组中只有一个重复的数字，但它可能不止重复出现一次。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) break;
        }
        fast = 0;
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

```