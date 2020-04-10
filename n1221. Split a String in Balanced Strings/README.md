# Split a String in Balanced Strings *
- 题目地址: [https://leetcode-cn.com/problems/split-a-string-in-balanced-strings](https://leetcode-cn.com/problems/split-a-string-in-balanced-strings)
- 执行时间: 0 ms
- 内存消耗: 6.3 MB
- 通过日期: 2020-04-09 09:20

## 题目内容
<p>在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。</p>

<p>给出一个平衡字符串 <code>s</code>，请你将它分割成尽可能多的平衡字符串。</p>

<p>返回可以通过分割得到的平衡字符串的最大数量。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "RLRRLLRLRL"
<strong>输出：</strong>4
<strong>解释：</strong>s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "RLLLLRRRLR"
<strong>输出：</strong>3
<strong>解释：</strong>s 可以分割为 "RL", "LLLRRR", "LR", 每个子字符串中都包含相同数量的 'L' 和 'R'。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "LLLLRRRR"
<strong>输出：</strong>1
<strong>解释：</strong>s 只能保持原样 "LLLLRRRR".
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 1000</code></li>
	<li><code>s[i] = 'L' 或 'R'</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, ans = 0;
        for(auto ch : s) {
            if(ch == 'R') {
                cnt++;
            } else {
                cnt--;
            }
            if(cnt == 0) {
                ans++;
            }
        }
        return ans;
    }
};

```