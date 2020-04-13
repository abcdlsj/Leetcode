# String Matching in an Array *
- 题目地址: [https://leetcode-cn.com/problems/string-matching-in-an-array](https://leetcode-cn.com/problems/string-matching-in-an-array)
- 执行时间: 16 ms
- 内存消耗: 9.1 MB
- 通过日期: 2020-04-13 17:58

## 题目内容
<p>给你一个字符串数组 <code>words</code> ，数组中的每个字符串都可以看作是一个单词。请你按 <strong>任意</strong> 顺序返回 <code>words</code> 中是其他单词的子字符串的所有单词。</p>

<p>如果你可以删除 <code>words[j]</code> 最左侧和/或最右侧的若干字符得到 <code>word[i]</code> ，那么字符串 <code>words[i]</code> 就是 <code>words[j]</code> 的一个子字符串。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["mass","as","hero","superhero"]
<strong>输出：</strong>["as","hero"]
<strong>解释：</strong>"as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
["hero","as"] 也是有效的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["leetcode","et","code"]
<strong>输出：</strong>["et","code"]
<strong>解释：</strong>"et" 和 "code" 都是 "leetcode" 的子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["blue","green","bu"]
<strong>输出：</strong>[]
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 100</code></li>
	<li><code>1 <= words[i].length <= 30</code></li>
	<li><code>words[i]</code> 仅包含小写英文字母。</li>
	<li>题目数据 <strong>保证</strong> 每个 <code>words[i]</code> 都是独一无二的。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(auto w : words) {
            for(auto s : words) {
                if(s == w) continue;
                if(s.find(w) != -1) {
                    res.push_back(w);
                    break;
                } 
            }
        }
        return res;
    }
};

```