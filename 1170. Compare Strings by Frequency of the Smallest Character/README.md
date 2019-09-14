# Compare Strings by Frequency of the Smallest Character :star:
- 题目地址: [https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character](https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character)
- 执行时间: 20 ms 
- 内存消耗: 10.7 MB
- 通过日期: 2019-08-25 20:51

## 题目内容
<p>我们来定义一个函数 <code>f(s)</code>，其中传入参数 <code>s</code> 是一个非空字符串；该函数的功能是统计 <code>s</code>  中（按字典序比较）最小字母的出现频次。</p>

<p>例如，若 <code>s = "dcce"</code>，那么 <code>f(s) = 2</code>，因为最小的字母是 <code>"c"</code>，它出现了 2 次。</p>

<p>现在，给你两个字符串数组待查表 <code>queries</code> 和词汇表 <code>words</code>，请你返回一个整数数组 <code>answer</code> 作为答案，其中每个 <code>answer[i]</code> 是满足 <code>f(queries[i])</code> < <code>f(W)</code> 的词的数目，<code>W</code> 是词汇表 <code>words</code> 中的词。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>queries = ["cbd"], words = ["zaaaz"]
<strong>输出：</strong>[1]
<strong>解释：</strong>查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= queries.length <= 2000</code></li>
	<li><code>1 <= words.length <= 2000</code></li>
	<li><code>1 <= queries[i].length, words[i].length <= 10</code></li>
	<li><code>queries[i][j]</code>, <code>words[i][j]</code> 都是小写英文字母</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int t[26];
    int f(string s)
    {
        memset(t,0,sizeof(t));
        for(char c:s)
            t[c-'a']++;
        for(int i=0;i<26;i++)
            if(t[i]) 
                return t[i];
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size(),m=words.size();
        vector <int> ans;
        vector <int> sum(15,0);
        for(string s:words)
            sum[f(s)]++;
        for(int i=10;i>=0;i--)
            sum[i]+=sum[i+1];
        for(string s:queries)
            ans.push_back(sum[f(s)+1]);
        return ans;
    }
};

```