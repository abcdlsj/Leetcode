# 替换空格 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof)
- 执行时间: 4 ms
- 内存消耗: 8.7 MB
- 通过日期: 2020-03-05 17:00

## 题目内容
<p>请实现一个函数，把字符串 <code>s</code> 中的每个空格替换成"%20"。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "We are happy."
<strong>输出：</strong>"We%20are%20happy."</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= s 的长度 <= 10000</code></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(auto c : s) {
            if(c == ' ')
                res += "%20";
            else res += c;
        }
        return res;
    }
};

```