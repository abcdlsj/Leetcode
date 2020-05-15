# Subarray Sum Equals K **
- 题目地址: [https://leetcode-cn.com/problems/subarray-sum-equals-k](https://leetcode-cn.com/problems/subarray-sum-equals-k)
- 执行时间: 108 ms
- 内存消耗: 22.1 MB
- 通过日期: 2020-05-15 14:21

## 题目内容
<p>给定一个整数数组和一个整数 <strong>k，</strong>你需要找到该数组中和为 <strong>k </strong>的连续的子数组的个数。</p>

<p><strong>示例 1 :</strong></p>

<pre>
<strong>输入:</strong>nums = [1,1,1], k = 2
<strong>输出:</strong> 2 , [1,1] 与 [1,1] 为两种不同的情况。
</pre>

<p><strong>说明 :</strong></p>

<ol>
	<li>数组的长度为 [1, 20,000]。</li>
	<li>数组中元素的范围是 [-1000, 1000] ，且整数 <strong>k </strong>的范围是 [-1e7, 1e7]。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> map;

        map[0] = 1; 
        for (auto item : nums) {
            sum += item;
            if (map.find(sum - k) != map.end()) {
                count += map[sum - k];
            }
            if (map.find(sum) == map.end()) {
                map[sum] = 1;
            } else {
                map[sum]++;
            }
        }

        return count;
    }
};

```