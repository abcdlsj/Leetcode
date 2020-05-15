# Group Anagrams **
- 题目地址: [https://leetcode-cn.com/problems/group-anagrams](https://leetcode-cn.com/problems/group-anagrams)
- 执行时间: 72 ms
- 内存消耗: 17.3 MB
- 通过日期: 2020-05-10 08:04

## 题目内容
<p>给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>["eat", "tea", "tan", "ate", "nat", "bat"]</code>
<strong>输出:</strong>
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]</pre>

<p><strong>说明：</strong></p>

<ul>
	<li>所有输入均为小写字母。</li>
	<li>不考虑答案输出的顺序。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto str : strs) {
            string ss = str;
            sort(str.begin(), str.end());
            map[str].push_back(ss);
        }
        vector<vector<string>> res;
        for(pair<string, vector<string>> x : map) {
            res.push_back(x.second);
        }
        return res;
    }
};

```