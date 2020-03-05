# 数组中重复的数字 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof)
- 执行时间: 68 ms
- 内存消耗: 30.5 MB
- 通过日期: 2020-03-05 12:03

## 题目内容
<p>找出数组中重复的数字。</p>

<p><br>
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
[2, 3, 1, 0, 2, 5, 3]
<strong>输出：</strong>2 或 3 
</pre>



<p><strong>限制：</strong></p>

<p><code>2 <= n <= 100000</code></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            if(map[nums[i]] > 1) return nums[i];
        }
        return nums[0];
    }
};

```