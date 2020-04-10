# The Masseuse LCCI *
- 题目地址: [https://leetcode-cn.com/problems/the-masseuse-lcci](https://leetcode-cn.com/problems/the-masseuse-lcci)
- 执行时间: 4 ms
- 内存消耗: 7.8 MB
- 通过日期: 2020-03-24 17:21

## 题目内容
<p>一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。</p>

<p><strong>注意：</strong>本题相对原题稍作改动</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong> [1,2,3,1]
<strong>输出：</strong> 4
<strong>解释：</strong> 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong> [2,7,9,3,1]
<strong>输出：</strong> 12
<strong>解释：</strong> 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong> [2,1,4,5,3,1,1,3]
<strong>输出：</strong> 12
<strong>解释：</strong> 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> cnt(nums);
        cnt[1] = max(cnt[0], cnt[1]);
        for(int i = 2; i < nums.size(); i++) {
            cnt[i] = max(cnt[i] + cnt[i-2], cnt[i-1]);
        }
        return cnt[nums.size() - 1];
    }
};

```