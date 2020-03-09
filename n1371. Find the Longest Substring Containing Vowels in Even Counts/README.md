# Find the Longest Substring Containing Vowels in Even Counts **
- 题目地址: [https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts](https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts)
- 执行时间: 188 ms
- 内存消耗: 18.5 MB
- 通过日期: 2020-03-08 16:04

## 题目内容
<p>给你一个字符串 <code>s</code> ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。</p>



<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "eleetminicoworoep"
<strong>输出：</strong>13
<strong>解释：</strong>最长子字符串是 "leetminicowor" ，它包含 <strong>e，i，o</strong> 各 2 个，以及 0 个 <strong>a</strong>，<strong>u </strong>。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcodeisgreat"
<strong>输出：</strong>5
<strong>解释：</strong>最长子字符串是 "leetc" ，其中包含 2 个 <strong>e</strong> 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "bcbcbc"
<strong>输出：</strong>6
<strong>解释：</strong>这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 <strong>a，</strong><strong>e，</strong><strong>i，</strong><strong>o，</strong><strong>u</strong> 都出现了 0 次。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 5 x 10^5</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        string zero = "aeiou";
        vector<int> index(1 << 5, INT_MAX);
        index[0] = 0;
        int stage = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 5; j++) 
                if(s[i - 1] == zero[j])
                    stage ^= (1 << j);
            index[stage] = min(index[stage], i);
            res = max(res, i - index[stage]);
        }
        return res;
    }
};

```