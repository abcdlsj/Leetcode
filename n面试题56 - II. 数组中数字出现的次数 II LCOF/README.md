# 数组中数字出现的次数 II LCOF **
- 题目地址: [https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof)
- 执行时间: 112 ms
- 内存消耗: 16.1 MB
- 通过日期: 2020-04-27 19:43

## 题目内容
<p>在一个数组 <code>nums</code> 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,3,3]
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,1,7,9,7,9,7]
<strong>输出：</strong>1</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10000</code></li>
	<li><code>1 <= nums[i] < 2^31</code></li>
</ul>




## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(auto num : nums) {
                if((1 << i & num) != 0) {
                    cnt++;
                }
            }
            if(cnt % 3 != 0) {
                ans += 1 << i;
            }
        }
        return ans;
    }
};

```