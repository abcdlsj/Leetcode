# Single Number II **
- 题目地址: [https://leetcode-cn.com/problems/single-number-ii](https://leetcode-cn.com/problems/single-number-ii)
- 执行时间: 24 ms
- 内存消耗: 9.7 MB
- 通过日期: 2019-08-12 11:49

## 题目内容
<p>给定一个<strong>非空</strong>整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。</p>

<p><strong>说明：</strong></p>

<p>你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [2,2,3,2]
<strong>输出:</strong> 3
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [0,1,0,1,0,1,99]
<strong>输出:</strong> 99</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i;
        if(nums.size()<=3)
            return nums[0];
        for(i=0;i+3<nums.size();i+=3)
            if(nums[i]!=nums[i+1])
                return nums[i];
        return nums[nums.size()-1];
    }
};

```