# 滑动窗口的最大值 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof)
- 执行时间: 40 ms
- 内存消耗: 16.1 MB
- 通过日期: 2020-04-17 20:04

## 题目内容
<p>给定一个数组 <code>nums</code> 和滑动窗口的大小 <code>k</code>，请找出所有滑动窗口里的最大值。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <em>nums</em> = <code>[1,3,-1,-3,5,3,6,7]</code>, 和 <em>k</em> = 3
<strong>输出: </strong><code>[3,3,5,5,6,7] 
<strong>解释: 
</strong></code>
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7</pre>



<p><strong>提示：</strong></p>

<p>你可以假设 <em>k </em>总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。</p>

<p>注意：本题与主站 239 题相同：<a href="https://leetcode-cn.com/problems/sliding-window-maximum/">https://leetcode-cn.com/problems/sliding-window-maximum/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deque; vector<int> res;
        if(nums.size() == 0) return res;
        for(int i = 0; i < nums.size(); i++) {
            if(!deque.empty() && i - deque.front() + 1 > k) {
                deque.pop_front();
            }
            while(!deque.empty() && nums[i] > nums[deque.back()]) {
                deque.pop_back();
            }
            deque.push_back(i);
            if(i + 1 >= k) {
                res.push_back(nums[deque.front()]);
            }
        }
        return res;
    }
};

```