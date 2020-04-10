# String to URL LCCI *
- 题目地址: [https://leetcode-cn.com/problems/string-to-url-lcci](https://leetcode-cn.com/problems/string-to-url-lcci)
- 执行时间: 100 ms
- 内存消耗: 25.6 MB
- 通过日期: 2020-03-30 09:12

## 题目内容
<p>URL化。编写一种方法，将字符串中的空格全部替换为<code>%20</code>。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用<code>Java</code>实现的话，请使用字符数组实现，以便直接在数组上操作。）</p>

<p><strong>示例1:</strong></p>

<pre><strong> 输入</strong>："Mr John Smith    ", 13
<strong> 输出</strong>："Mr%20John%20Smith"
</pre>

<p><strong>示例2:</strong></p>

<pre><strong> 输入</strong>："               ", 5
<strong> 输出</strong>："%20%20%20%20%20"
</pre>

<p><strong>提示：</strong></p>

<ol>
	<li>字符串长度在[0, 500000]范围内。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res;
        for(int i = 0; i < length; ++i) {
            if(S[i] != ' ') res.push_back(S[i]);
            else res.append("%20");
        }
        return res;
    }
};

```