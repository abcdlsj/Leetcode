# Next Permutation **
- 题目地址: [https://leetcode-cn.com/problems/next-permutation](https://leetcode-cn.com/problems/next-permutation)
- 执行时间: 8 ms
- 内存消耗: 6.9 MB
- 通过日期: 2020-03-31 23:38

## 题目内容
<p>实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。</p>

<p>如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。</p>

<p>必须<strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">原地</a></strong>修改，只允许使用额外常数空间。</p>

<p>以下是一些例子，输入位于左侧列，其相应输出位于右侧列。<br>
<code>1,2,3</code> → <code>1,3,2</code><br>
<code>3,2,1</code> → <code>1,2,3</code><br>
<code>1,1,5</code> → <code>1,5,1</code></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) return;
        int pos = nums.size() - 1;
        while(pos > 0 && nums[pos] <= nums[pos - 1]) pos --;
        reverse(nums.begin() + pos, nums.end());
        if(pos > 0) {
            for(int start = pos; start < nums.size(); ++start) {
                if(nums[start] > nums[pos - 1]) {
                    swap(nums[start], nums[pos - 1]);
                    break;
                }
            }
        }
    }
};

```