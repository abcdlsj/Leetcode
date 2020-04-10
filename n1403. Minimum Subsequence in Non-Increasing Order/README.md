# Minimum Subsequence in Non-Increasing Order *
- 题目地址: [https://leetcode-cn.com/problems/minimum-subsequence-in-non-increasing-order](https://leetcode-cn.com/problems/minimum-subsequence-in-non-increasing-order)
- 执行时间: 64 ms
- 内存消耗: 10.7 MB
- 通过日期: 2020-04-05 10:40

## 题目内容
<p>给你一个数组 <code>nums</code>，请你从中抽取一个子序列，满足该子序列的元素之和 <strong>严格</strong> 大于未包含在该子序列中的各元素之和。</p>

<p>如果存在多个解决方案，只需返回 <strong>长度最小</strong> 的子序列。如果仍然有多个解决方案，则返回 <strong>元素之和最大</strong> 的子序列。</p>

<p>与子数组不同的地方在于，「数组的子序列」不强调元素在原数组中的连续性，也就是说，它可以通过从数组中分离一些（也可能不分离）元素得到。</p>

<p><strong>注意</strong>，题目数据保证满足所有约束条件的解决方案是 <strong>唯一</strong> 的。同时，返回的答案应当按 <strong>非递增顺序</strong> 排列。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [4,3,10,9,8]
<strong>输出：</strong>[10,9] 
<strong>解释：</strong>子序列 [10,9] 和 [10,8] 是最小的、满足元素之和大于其他各元素之和的子序列。但是 [10,9] 的元素之和最大。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,4,7,6,7]
<strong>输出：</strong>[7,7,6] 
<strong>解释：</strong>子序列 [7,7] 的和为 14 ，不严格大于剩下的其他元素之和（14 = 4 + 4 + 6）。因此，[7,6,7] 是满足题意的最小子序列。注意，元素按非递增顺序返回。  
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [6]
<strong>输出：</strong>[6]
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 500</code></li>
	<li><code>1 <= nums[i] <= 100</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() == 0) return {};
        sort(nums.rbegin(), nums.rend());
        int i = 0;
        vector<int> path;
        while(accumulate(path.begin(), path.end(), 0) <= (accumulate(nums.begin(), nums.end(), 0) / 2)) {
            path.push_back(nums[i]);
            i++;
        }
        return path;
    }
};

```