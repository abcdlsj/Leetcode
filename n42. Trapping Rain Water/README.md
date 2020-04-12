# Trapping Rain Water ***
- 题目地址: [https://leetcode-cn.com/problems/trapping-rain-water](https://leetcode-cn.com/problems/trapping-rain-water)
- 执行时间: 8 ms
- 内存消耗: 6.7 MB
- 通过日期: 2020-04-04 16:31

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
        int ans = 0, i = 0, j = height.size() - 1, lmax = height[0], rmax = height[height.size() - 1];
        while(i < j) {
            if(lmax < rmax) {
                ans += lmax - height[i];
                lmax = max(lmax, height[++i]);
            } else {
                ans += rmax - height[j];
                rmax = max(rmax, height[--j]);
            }
        }
        return ans;
    }
};

```