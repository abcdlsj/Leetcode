# Letter Combinations of a Phone Number **
- 题目地址: [https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number)
- 执行时间: 4 ms
- 内存消耗: 6.8 MB
- 通过日期: 2020-03-27 22:17

## 题目内容
<p>给定一个仅包含数字 <code>2-9</code> 的字符串，返回所有它能表示的字母组合。</p>

<p>给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/original_images/17_telephone_keypad.png" style="width: 200px;"></p>

<p><strong>示例:</strong></p>

<pre><strong>输入：</strong>"23"
<strong>输出：</strong>["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
</pre>

<p><strong>说明:</strong><br>
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};
        vector<string> res;
        if(digits == "") return res;
        dfs(res, "", digits, table, 0);
        return res;
    }
    void dfs(vector<string> &res, string str, string &digits, unordered_map<char, string> &table, int k) {
        if(str.size() == digits.size()) {
            res.push_back(str);
            return ;
        }
        string tmp = table[digits[k]];
        for(auto c : tmp) {
            str += c;
            dfs(res, str, digits, table, k+1);
            str.pop_back();
        }
        return ;
    }
};

```