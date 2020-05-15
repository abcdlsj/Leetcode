# Single Number *
- 题目地址: [https://leetcode-cn.com/problems/single-number](https://leetcode-cn.com/problems/single-number)
- 执行时间: 20 ms
- 内存消耗: 11.5 MB
- 通过日期: 2020-05-14 07:27

## 题目内容
<p>给定一个<strong>非空</strong>整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。</p>

<p><strong>说明：</strong></p>

<p>你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [2,2,1]
<strong>输出:</strong> 1
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [4,1,2,1,2]
<strong>输出:</strong> 4</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
};

```