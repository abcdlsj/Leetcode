# 左旋转字符串 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof)
- 执行时间: 4 ms
- 内存消耗: 8 MB
- 通过日期: 2020-04-14 21:42

## 题目内容
<p>字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> s = "abcdefg", k = 2
<strong>输出: </strong>"cdefgab"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> s = "lrloseumgh", k = 6
<strong>输出: </strong>"umghlrlose"
</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= k < s.length <= 10000</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string cnt = s + s;
        return string(cnt.begin() + n, cnt.begin() + n + s.size());
    }
};

```