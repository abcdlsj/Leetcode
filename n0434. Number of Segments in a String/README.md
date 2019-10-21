# Number of Segments in a String *
- 题目地址: [https://leetcode-cn.com/problems/number-of-segments-in-a-string](https://leetcode-cn.com/problems/number-of-segments-in-a-string)
- 执行时间: 4 ms 
- 内存消耗: 8.4 MB
- 通过日期: 2019-08-30 15:23

## 题目内容
<p>统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。</p>

<p>请注意，你可以假定字符串里不包括任何不可打印的字符。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> "Hello, my name is John"
<strong>输出:</strong> 5
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