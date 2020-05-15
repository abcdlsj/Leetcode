# Trapping Rain Water ***
- 题目地址: [https://leetcode-cn.com/problems/trapping-rain-water](https://leetcode-cn.com/problems/trapping-rain-water)
- 执行时间: 8 ms
- 内存消耗: 6.7 MB
- 通过日期: 2020-05-04 12:27

## 题目内容
<p>给定 <em>n</em> 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png" style="height: 161px; width: 412px;"></p>

<p><small>上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 <strong>感谢 Marcos</strong> 贡献此图。</small></p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>输出:</strong> 6</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        // 每次能接到的水是 max(leftmax, rightmax) - height[i] 这样暴力就能做出来了

        // 双指针做法
        // 双指针从左右两边向中间计算，lefMax 存储左边到 left 的最大值，rightMax 存储右边到 right 的最大值，如果 lefMax <= rightMax 那么因为短板效应，可以计算左边，同理如右
        int left = 0, right = height.size() - 1, lefMax = height[left], rightMax = height[right], ans = 0;
        while(left < right) {
            if(lefMax <= rightMax) {
                ans += lefMax - height[left];
                left++;
                lefMax = max(lefMax, height[left]);
            }  else {
                ans += rightMax - height[right];
                right--;
                rightMax = max(rightMax, height[right]);
            }
        }
        return ans;
    }
};

```