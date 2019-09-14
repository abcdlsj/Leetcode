# Add Binary :star:
- 题目地址: [https://leetcode-cn.com/problems/add-binary](https://leetcode-cn.com/problems/add-binary)
- 执行时间: 4 ms 
- 内存消耗: 8.5 MB
- 通过日期: 2019-09-10 23:50

## 题目内容
<p>给定两个二进制字符串，返回他们的和（用二进制表示）。</p>

<p>输入为<strong>非空</strong>字符串且只包含数字 <code>1</code> 和 <code>0</code>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> a = "11", b = "1"
<strong>输出:</strong> "100"</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> a = "1010", b = "1011"
<strong>输出:</strong> "10101"</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        s.reserve(a.size()+b.size());
        int i=a.size()-1,j=b.size()-1;
        int c=0;
        while(i>=0||j>=0||c==1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
			c += j >= 0 ? b[j--] - '0' : 0;
            s.push_back((c & 1) + '0');
            c>>=1;
        }
        reverse(s.begin(), s.end());
		return s;
    }
};

```