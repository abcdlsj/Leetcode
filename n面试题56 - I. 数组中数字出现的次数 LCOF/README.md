# 数组中数字出现的次数 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof)
- 执行时间: 44 ms
- 内存消耗: 16 MB
- 通过日期: 2020-04-28 12:28

## 题目内容
<p>一个整型数组 <code>nums</code> 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [4,1,4,6]
<strong>输出：</strong>[1,6] 或 [6,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,10,4,1,4,3,3]
<strong>输出：</strong>[2,10] 或 [10,2]</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 10000</code></li>
</ul>




## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xorNum = 0, ans1 = 0;
        for(auto num : nums) {
            xorNum ^= num;
        }
        // 得到最后一个 1
        int flag = xorNum & (-xorNum);
        for(auto num : nums) {
            if((flag & num) != 0) {
                ans1 ^= num;
            }
        }
        return {ans1, xorNum ^ ans1};
    }
};

```