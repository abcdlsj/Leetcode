# Sliding Window Maximum ***
- 题目地址: [https://leetcode-cn.com/problems/sliding-window-maximum](https://leetcode-cn.com/problems/sliding-window-maximum)
- 执行时间: 48 ms
- 内存消耗: 12.1 MB
- 通过日期: 2020-04-17 20:05

## 题目内容
<p>给定一个数组 <em>nums</em>，有一个大小为 <em>k </em>的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 <em>k</em> 个数字。滑动窗口每次只向右移动一位。</p>

<p>返回滑动窗口中的最大值。</p>



<p><strong>进阶：</strong></p>

<p>你能在线性时间复杂度内解决此题吗？</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <em>nums</em> = <code>[1,3,-1,-3,5,3,6,7]</code>, 和 <em>k</em> = 3
<strong>输出: </strong><code>[3,3,5,5,6,7] 
<strong>解释: 
</strong></code>
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7       <strong>5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong></pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>-10^4 <= nums[i] <= 10^4</code></li>
	<li><code>1 <= k <= nums.length</code></li>
</ul>


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