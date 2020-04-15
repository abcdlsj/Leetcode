# Product of Array Except Self **
- 题目地址: [https://leetcode-cn.com/problems/product-of-array-except-self](https://leetcode-cn.com/problems/product-of-array-except-self)
- 执行时间: 20 ms
- 内存消耗: 15.5 MB
- 通过日期: 2020-04-14 22:22

## 题目内容
<p>给你一个长度为 <em>n</em> 的整数数组 <code>nums</code>，其中 <em>n</em> > 1，返回输出数组 <code>output</code> ，其中 <code>output[i]</code> 等于 <code>nums</code> 中除 <code>nums[i]</code> 之外其余各元素的乘积。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>[1,2,3,4]</code>
<strong>输出:</strong> <code>[24,12,8,6]</code></pre>



<p><strong>提示：</strong>题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。</p>

<p><strong>说明: </strong>请<strong>不要使用除法，</strong>且在 O(<em>n</em>) 时间复杂度内完成此题。</p>

<p><strong>进阶：</strong><br>
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组<strong>不被视为</strong>额外空间。）</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for(int i = 0, left = 1; i < nums.size(); left *= nums[i], i++) {
            res[i] = left;
        }
        for(int i = nums.size() - 1, right = 1; i >= 0; right *= nums[i], i--) {
            res[i] *= right;
        }
        return res;
    }
};

```