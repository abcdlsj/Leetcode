# 和为s的连续正数序列 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof)
- 执行时间: 0 ms
- 内存消耗: 6.9 MB
- 通过日期: 2020-04-14 12:55

## 题目内容
<p>输入一个正整数 <code>target</code> ，输出所有和为 <code>target</code> 的连续正整数序列（至少含有两个数）。</p>

<p>序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = 9
<strong>输出：</strong>[[2,3,4],[4,5]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = 15
<strong>输出：</strong>[[1,2,3,4,5],[4,5,6],[7,8]]
</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= target <= 10^5</code></li>
</ul>




## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 2, sum = left;
        vector<int> path;
        vector<vector<int>> res;
        while(right < target && left < right) {
            if(sum < target) {
                sum += right++;
            } else if(sum > target) {
                sum -= left++;
            } else {
                for(int i = left; i < right; i++) path.push_back(i);
                res.push_back(path);
                path.clear();
                sum -= left++;
            }
        }
        return res;
    }
};

```