# Can Make Palindrome from Substring **
- 题目地址: [https://leetcode-cn.com/problems/can-make-palindrome-from-substring](https://leetcode-cn.com/problems/can-make-palindrome-from-substring)
- 执行时间: 540 ms
- 内存消耗: 59.5 MB
- 通过日期: 2019-09-01 22:31

## 题目内容
<p>给你一个字符串 <code>s</code>，请你对 <code>s</code> 的子串进行检测。</p>

<p>每次检测，待检子串都可以表示为 <code>queries[i] = [left, right, k]</code>。我们可以 <strong>重新排列</strong> 子串 <code>s[left], ..., s[right]</code>，并从中选择 <strong>最多</strong> <code>k</code> 项替换成任何小写英文字母。 </p>

<p>如果在上述检测过程中，子串可以变成回文形式的字符串，那么检测结果为 <code>true</code>，否则结果为 <code>false</code>。</p>

<p>返回答案数组 <code>answer[]</code>，其中 <code>answer[i]</code> 是第 <code>i</code> 个待检子串 <code>queries[i]</code> 的检测结果。</p>

<p>注意：在替换时，子串中的每个字母都必须作为 <strong>独立的</strong> 项进行计数，也就是说，如果 <code>s[left..right] = "aaa"</code> 且 <code>k = 2</code>，我们只能替换其中的两个字母。（另外，任何检测都不会修改原始字符串 <code>s</code>，可以认为每次检测都是独立的）</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
<strong>输出：</strong>[true,false,false,true,true]
<strong>解释：</strong>
queries[0] : 子串 = "d"，回文。
queries[1] : 子串 = "bc"，不是回文。
queries[2] : 子串 = "abcd"，只替换 1 个字符是变不成回文串的。
queries[3] : 子串 = "abcd"，可以变成回文的 "abba"。 也可以变成 "baab"，先重新排序变成 "bacd"，然后把 "cd" 替换为 "ab"。
queries[4] : 子串 = "abcda"，可以变成回文的 "abcba"。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length, queries.length <= 10^5</code></li>
	<li><code>0 <= queries[i][0] <= queries[i][1] < s.length</code></li>
	<li><code>0 <= queries[i][2] <= s.length</code></li>
	<li><code>s</code> 中只有小写英文字母</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        int cnt[n+1][26];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
                cnt[i+1][j]=cnt[i][j];
            cnt[i+1][s[i]-'a']++;
        }
        vector<bool> ans;
        for(auto q:queries)
        {
            int l=q[0],r=q[1]+1,k=q[2];
            int nk=0;
            for(int i=0;i<26;i++)
                if((cnt[r][i]-cnt[l][i])&1) nk++;
            ans.push_back((nk/2)<=k);
        }
        return ans;
    }
};

```