# Word Break II ***
- 题目地址: [https://leetcode-cn.com/problems/word-break-ii](https://leetcode-cn.com/problems/word-break-ii)
- 执行时间: 36 ms
- 内存消耗: 10.4 MB
- 通过日期: 2020-05-13 11:48

## 题目内容
<p>给定一个<strong>非空</strong>字符串 <em>s</em> 和一个包含<strong>非空</strong>单词列表的字典 <em>wordDict</em>，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>分隔时可以重复使用字典中的单词。</li>
	<li>你可以假设字典中没有重复的单词。</li>
</ul>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:
</strong>s = "<code>catsanddog</code>"
wordDict = <code>["cat", "cats", "and", "sand", "dog"]</code>
<strong>输出:
</strong><code>[
  "cats and dog",
  "cat sand dog"
]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:
</strong>s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
<strong>输出:
</strong>[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
<strong>解释:</strong> 注意你可以重复使用字典中的单词。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:
</strong>s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>输出:
</strong>[]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string> > map;
        return backtrack(map, wordDict, s);
    }
    vector<string> backtrack(unordered_map<string, vector<string>> &map, vector<string> &wordDict, string s) {
        if (map.count(s)) return map[s];
        if (s.empty()) return {""};

        vector<string> res;
        for (auto word : wordDict) {
            if(s.substr(0, word.size()) != word) continue;
            vector<string> tmp = backtrack(map, wordDict, s.substr(word.size()));
            for(auto ele : tmp) {
                res.push_back(word + (ele.empty() ? "": " ") + ele);
            }
        }
        
        map[s] = res;
        return res;
    }
};

```