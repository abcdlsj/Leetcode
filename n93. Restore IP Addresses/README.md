# Restore IP Addresses **
- 题目地址: [https://leetcode-cn.com/problems/restore-ip-addresses](https://leetcode-cn.com/problems/restore-ip-addresses)
- 执行时间: 8 ms
- 内存消耗: 6.7 MB
- 通过日期: 2020-04-08 21:31

## 题目内容
<p>给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> "25525511135"
<strong>输出:</strong> <code>["255.255.11.135", "255.255.111.35"]</code></pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> segments;
        backtrack(res, segments, s, 0);
        return res;
    }
    void backtrack(vector<string> &res, vector<string> &segments, const string &s, int start) {
        if(start == s.size() && segments.size() == 4) {
            string tmp = "";
            for(int i = 0; i < 3; i++) {
                tmp += segments[i] + '.';
            }
            tmp += segments[3];
            res.push_back(tmp);
        }

        for(int i = start; i < s.size() && i < start + 3 && segments.size() <= 4; i++) {
            string tmp = s.substr(start, i - start + 1);
            if((tmp[0] == '0' && tmp.size() > 1 ) || stoi(tmp) > 255 || stoi(tmp) < 0) {
                break;
            } else {
                segments.push_back(tmp);
                backtrack(res, segments, s, i + 1);
                segments.pop_back();
            }
        }
    }
};

```