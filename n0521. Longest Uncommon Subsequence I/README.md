# longest-uncommon-subsequence-i *
- 题目地址: [https://leetcode-cn.com/problems/longest-uncommon-subsequence-i](https://leetcode-cn.com/problems/longest-uncommon-subsequence-i)
- 执行时间: 8 ms 
- 内存消耗: 8.3 MB
- 通过日期: 2019-08-30 15:23

## 题目内容
<p>给定两个字符串，你需要从这两个字符串中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。</p> 
<p>子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。</p>

<p>输入为两个字符串，输出最长特殊序列的长度。如果不存在，则返回 0。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>"aba", "cdc"
<strong>输出:</strong>3
<strong>解析:</strong>最长特殊序列可为 "aba" (或 "cdc")
</pre>



## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int ans=0;
        if(n==0) return 0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==' '&&s[i+1]!=' ')
                ans++;
        }
        return (s[0]==' ')?ans:ans+1;
    }
};

```