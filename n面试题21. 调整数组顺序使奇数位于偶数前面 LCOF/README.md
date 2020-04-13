# 调整数组顺序使奇数位于偶数前面 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof)
- 执行时间: 40 ms
- 内存消耗: 18.1 MB
- 通过日期: 2020-04-13 09:00

## 题目内容
<p>输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>[1,3,2,4] 
<strong>注：</strong>[3,1,2,4] 也是正确的答案之一。</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= nums.length <= 50000</code></li>
	<li><code>1 <= nums[i] <= 10000</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            while(i < j && nums[i] % 2 == 1) i++;
            while(i < j && nums[j] % 2 == 0) j--;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

```