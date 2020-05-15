# Count Number of Teams **
- 题目地址: [https://leetcode-cn.com/problems/count-number-of-teams](https://leetcode-cn.com/problems/count-number-of-teams)
- 执行时间: 8 ms
- 内存消耗: 7.6 MB
- 通过日期: 2020-05-15 11:04

## 题目内容
<p> <code>n</code> 名士兵站成一排。每个士兵都有一个 <strong>独一无二</strong> 的评分 <code>rating</code> 。</p>

<p>每 <strong>3</strong> 个士兵可以组成一个作战单位，分组规则如下：</p>

<ul>
	<li>从队伍中选出下标分别为 <code>i</code>、<code>j</code>、<code>k</code> 的 3 名士兵，他们的评分分别为 <code>rating[i]</code>、<code>rating[j]</code>、<code>rating[k]</code></li>
	<li>作战单位需满足： <code>rating[i] < rating[j] < rating[k]</code> 或者 <code>rating[i] > rating[j] > rating[k]</code> ，其中  <code>0 <= i < j < k < n</code></li>
</ul>

<p>请你返回按上述条件可以组建的作战单位数量。每个士兵都可以是多个作战单位的一部分。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>rating = [2,5,3,4,1]
<strong>输出：</strong>3
<strong>解释：</strong>我们可以组建三个作战单位 (2,3,4)、(5,4,1)、(5,3,1) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>rating = [2,1,3]
<strong>输出：</strong>0
<strong>解释：</strong>根据题目条件，我们无法组建作战单位。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>rating = [1,2,3,4]
<strong>输出：</strong>4
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rating.length</code></li>
	<li><code>1 <= n <= 200</code></li>
	<li><code>1 <= rating[i] <= 10^5</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0, n = rating.size();
        for (int i = 1; i < n - 1; i++) {
            int lless = 0, lmore = 0, rless = 0, rmore = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) lless++;
                else if (rating[j] > rating[i]) lmore++;
            }

            for (int j = i + 1; j < n; j++) {
                if (rating[j] < rating[i]) rless++;
                else if (rating[j] > rating[i]) rmore++;
            }

            ans += lless * rmore + lmore * rless;
        }
        return ans;
    }
};

```