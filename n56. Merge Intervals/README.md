# Merge Intervals **
- 题目地址: [https://leetcode-cn.com/problems/merge-intervals](https://leetcode-cn.com/problems/merge-intervals)
- 执行时间: 44 ms
- 内存消耗: 10.5 MB
- 通过日期: 2020-04-16 07:48

## 题目内容
<p>给出一个区间的集合，请合并所有重叠的区间。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [[1,3],[2,6],[8,10],[15,18]]
<strong>输出:</strong> [[1,6],[8,10],[15,18]]
<strong>解释:</strong> 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [[1,4],[4,5]]
<strong>输出:</strong> [[1,5]]
<strong>解释:</strong> 区间 [1,4] 和 [4,5] 可被视为重叠区间。</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        if(intervals.size() == 0 || intervals.size() == 1) return intervals;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

```