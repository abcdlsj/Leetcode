# Count Largest Group *
- 题目地址: [https://leetcode-cn.com/problems/count-largest-group](https://leetcode-cn.com/problems/count-largest-group)
- 执行时间: 4 ms
- 内存消耗: 5.9 MB
- 通过日期: 2020-04-04 22:49

## 题目内容
<p>给你一个整数 <code>n</code> 。请你先求出从 <code>1</code> 到 <code>n</code> 的每个整数 10 进制表示下的数位和（每一位上的数字相加），然后把数位和相等的数字放到同一个组中。</p>

<p>请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 13
<strong>输出：</strong>4
<strong>解释：</strong>总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
[1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>总共有 2 个大小为 1 的组 [1]，[2]。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 15
<strong>输出：</strong>6
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 24
<strong>输出：</strong>5
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10^4</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int gethe(int n) {
        int res = 0;
        while(n > 0) {
            res += n % 10;
            n = n / 10;
        }
        return res;
    }
    int countLargestGroup(int n) {
        vector<int> cnt(37, 0);
        int ans = 0, MAX = INT_MIN;
        for(int i = 1; i <= n; i++) {
            cnt[gethe(i)] ++;
            MAX = max(MAX, cnt[gethe(i)]);
        }
        for(auto c : cnt) {
            if (c == MAX) ans++;
        }
        return ans;
    }
};

```