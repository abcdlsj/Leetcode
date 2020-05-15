# Restore IP Addresses **
- 题目地址: [https://leetcode-cn.com/problems/restore-ip-addresses](https://leetcode-cn.com/problems/restore-ip-addresses)
- 执行时间: 4 ms
- 内存消耗: 6.9 MB
- 通过日期: 2020-05-12 11:25

## 题目内容
<p>给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。</p>

<p>有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 <code>'.' </code>分隔。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> "25525511135"
<strong>输出:</strong> <code>["255.255.11.135", "255.255.111.35"]</code></pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, segments;
        if(s.size() > 12 || s.size() < 4) return res;
        backtrack(res, segments, s, 0);
        return res;
    }
    void backtrack(vector<string> &res, vector<string> &segments, const string &s, int start) {
        if(start == s.size() && segments.size() == 4) {
            string ss;
            for(auto seg : segments) {
                ss += seg + '.';
            }
            res.push_back(ss.substr(0, ss.size() - 1));
        }

        for(int i = start; i < s.size() && i < start + 3 && segments.size() < 4; i++) {
            string ss = s.substr(start, i - start + 1);
            if((ss[0] == '0' && ss.size() != 1) || stoi(ss) > 255 || stoi(ss) < 0) {
                break;
            }
            else {
                segments.push_back(ss);
                backtrack(res, segments, s, i + 1);
                segments.pop_back();
            }
        }
    }
};

```