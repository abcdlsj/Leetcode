# Maximum Number of Balloons *
- 题目地址: [https://leetcode-cn.com/problems/maximum-number-of-balloons](https://leetcode-cn.com/problems/maximum-number-of-balloons)
- 执行时间: 8 ms
- 内存消耗: 8.9 MB
- 通过日期: 2019-09-15 14:07

## 题目内容
<p>给你一个字符串 <code>text</code>，你需要使用 <code>text</code> 中的字母来拼凑尽可能多的单词 <strong>"balloon"（气球）</strong>。</p>

<p>字符串 <code>text</code> 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 <strong>"balloon"</strong>。</p>



<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/14/1536_ex1_upd.jpeg" style="height: 35px; width: 154px;"></strong></p>

<pre><strong>输入：</strong>text = "nlaebolko"
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/14/1536_ex2_upd.jpeg" style="height: 35px; width: 233px;"></strong></p>

<pre><strong>输入：</strong>text = "loonbalxballpoon"
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = "leetcode"
<strong>输出：</strong>0
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= text.length <= 10^4</code></li>
	<li><code>text</code> 全部由小写英文字母组成</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int cnt[30];
    int maxNumberOfBalloons(string text) {
        memset(cnt,0,sizeof(cnt));
        for(auto c : text) ++cnt[c-'a'];
        
        return min(min(min(cnt['b'-'a'],cnt['a'-'a']),min(cnt['l'-'a']/2,cnt['o'-'a']/2)),cnt['n'-'a']);
    }
};

```