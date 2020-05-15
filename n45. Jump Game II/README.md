# Jump Game II ***
- 题目地址: [https://leetcode-cn.com/problems/jump-game-ii](https://leetcode-cn.com/problems/jump-game-ii)
- 执行时间: 8 ms
- 内存消耗: 7.7 MB
- 通过日期: 2020-05-04 09:47

## 题目内容
<p>给定一个非负整数数组，你最初位于数组的第一个位置。</p>

<p>数组中的每个元素代表你在该位置可以跳跃的最大长度。</p>

<p>你的目标是使用最少的跳跃次数到达数组的最后一个位置。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [2,3,1,1,4]
<strong>输出:</strong> 2
<strong>解释:</strong> 跳到最后一个位置的最小跳跃数是 <code>2</code>。
     从下标为 0 跳到下标为 1 的位置，跳 <code>1</code> 步，然后跳 <code>3</code> 步到达数组的最后一个位置。
</pre>

<p><strong>说明:</strong></p>

<p>假设你总是可以到达数组的最后一个位置。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, start = 0, end = 0;
        while(end < nums.size() - 1) {
            int max = end;
            for (int i = start; i  <= end; i++) {
                if(nums[i] + i > max) {
                    max = nums[i] + i;
                }
            }
            start = end + 1, end = max, steps++;
        }
        return steps;
    }
};

```