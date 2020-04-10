# Shortest Unsorted Continuous Subarray *
- 题目地址: [https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray)
- 执行时间: 100 ms
- 内存消耗: 26.1 MB
- 通过日期: 2020-04-03 16:37

## 题目内容
<p>给定一个整数数组，你需要寻找一个<strong>连续的子数组</strong>，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。</p>

<p>你找到的子数组应是<strong>最短</strong>的，请输出它的长度。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> [2, 6, 4, 8, 10, 9, 15]
<strong>输出:</strong> 5
<strong>解释:</strong> 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
</pre>

<p><strong>说明 :</strong></p>

<ol>
	<li>输入的数组长度范围在 [1, 10,000]。</li>
	<li>输入的数组可能包含<strong>重复</strong>元素 ，所以<strong>升序</strong>的意思是<strong><=。</strong></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    vector<int> cnt(nums);
    sort(nums.begin(), nums.end());
    int left = nums.size() - 1, right = 0;
    for(int i = 0; i < nums.size(); i++) {
        int k = nums.size() - i - 1;
        if(nums[i] != cnt[i]) left = min(left, i);
        if(nums[k] != cnt[k]) right = max(right, k);
    }
    return (right-left) > 0 ? (right-left+1) : 0;
    }
};

```