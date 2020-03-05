# Is Unique LCCI *
- 题目地址: [https://leetcode-cn.com/problems/is-unique-lcci](https://leetcode-cn.com/problems/is-unique-lcci)
- 执行时间: 4 ms
- 内存消耗: 8.3 MB
- 通过日期: 2020-03-05 14:23

## 题目内容
<p>实现一个算法，确定一个字符串 <code>s</code> 的所有字符是否全都不同。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> <code>s</code> = "leetcode"
<strong>输出:</strong> false 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> <code>s</code> = "abc"
<strong>输出:</strong> true
</pre>

<p><strong>限制：</strong></p>
<ul>
	<li><code>0 <= len(s) <= 100 </code></li>
	<li>如果你不使用额外的数据结构，会很加分。</li>
</ul>
    

## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isUnique(string astr) {
        int sign = 0;
        for(int i = 0; i < astr.length(); i++) {
            int index = 1 << (astr[i] - 'a');
            if((index & sign) != 0) return false;
            else sign |= index;
        }
        return true;
    }
};

```