# Shortest Supersequence LCCI **
- 题目地址: [https://leetcode-cn.com/problems/shortest-supersequence-lcci](https://leetcode-cn.com/problems/shortest-supersequence-lcci)
- 执行时间: 320 ms
- 内存消耗: 54.1 MB
- 通过日期: 2020-04-21 15:49

## 题目内容
<p>假设你有两个数组，一个长一个短，短的元素均不相同。找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。</p>

<p>返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。若不存在，返回空数组。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
big = <code>[7,5,9,0,2,1,3,<strong>5,7,9,1</strong>,1,5,8,8,9,7]
small = [1,5,9]</code>
<strong>输出: </strong>[7,10]</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
big = <code>[1,2,3]
small = [4]</code>
<strong>输出: </strong>[]</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>big.length <= 100000</code></li>
	<li><code>1 <= small.length <= 100000</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        int left = 0, right = 0, start = 0, minlen = INT_MAX, match = 0;
        vector<int> res;
        unordered_map<int, int> window, needs;
        for(auto num : small) needs[num]++;
        while(right < big.size()) {
            int numright = big[right];
            if(needs.count(numright)) {
                window[numright]++;
                if(window[numright] == needs[numright]) match++;
            }
            while(match == needs.size()) {
                if(right - left + 1 < minlen) {
                    start = left;
                    minlen = right - left + 1;
                }
                int numleft = big[left];
                if(needs.count(numleft)) {
                    window[numleft]--;
                    if(window[numleft] < needs[numleft]) match--;
                }
                left++;
            }
            right++;
        }
        if(minlen != INT_MAX) {
            res.push_back(start);
            res.push_back(start + minlen - 1);
        }
        return res;
    }
};

```