# Reconstruct Original Digits from English 
- 题目地址: [https://leetcode-cn.com/problems/reconstruct-original-digits-from-english](https://leetcode-cn.com/problems/reconstruct-original-digits-from-english)
- 执行时间: 20 ms
- 内存消耗: 11.8 MB
- 通过日期: 2019-08-25 21:29

## 题目内容
<p>给定一个<strong>非空</strong>字符串，其中包含字母顺序打乱的英文单词表示的数字<code>0-9</code>。按升序输出原始的数字。</p>

<p><strong>注意:</strong></p>

<ol>
	<li>输入只包含小写英文字母。</li>
	<li>输入保证合法并可以转换为原始的数字，这意味着像 "abc" 或 "zerone" 的输入是不允许的。</li>
	<li>输入字符串的长度小于 50,000。</li>
</ol>

<p><strong>示例 1:</strong></p>

<pre>
输入: "owoztneoer"

输出: "012" (zeroonetwo)
</pre>

<p><strong>示例 2:</strong></p>

<pre>
输入: "fviefuro"

输出: "45" (fourfive)
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string originalDigits(string s) {
        string result = "";
        vector<int> chCnt(128, 0);
        //统计各个字符出现的次数
        for (auto ch : s){
            chCnt[ch] += 1;
        }
        //zero one two three four five six seven eight nine
        //zero特征字母'z'
        if (chCnt['z'] > 0){
            result += string(chCnt['z'], '0');
        }
        //one特征字母'o'，减去zero中的'z',two中的'w',four中的'u'
        if (chCnt['o'] - chCnt['z'] - chCnt['w'] - chCnt['u'] > 0){
            result += string(chCnt['o'] - chCnt['z'] - chCnt['w'] - chCnt['u'], '1');
        }
        //two特征字母'w'
        if (chCnt['w'] > 0){
            result += string(chCnt['w'], '2');
        }
        //three特征字母'r'，减去zero中的'z'，four中的'u'
        if (chCnt['r'] - chCnt['z'] - chCnt['u'] > 0){
            result += string(chCnt['r'] - chCnt['z'] - chCnt['u'], '3');
        }
        //four特征字母'u'
        if (chCnt['u'] > 0){
            result += string(chCnt['u'] , '4');
        }
        //five特征字母'f'，减去four中的'u'
        if (chCnt['f'] - chCnt['u'] > 0){
            result += string(chCnt['f'] - chCnt['u'], '5');
        }
        //six特征字母'x'
        if (chCnt['x'] > 0){
            result += string(chCnt['x'], '6');
        }
        //seven特征字母's',减去six中的'x'
        if (chCnt['s'] - chCnt['x']> 0){
            result += string(chCnt['s'] - chCnt['x'], '7');
        }
        //eight特征字母'g'
        if (chCnt['g'] > 0){
            result += string(chCnt['g'], '8');
        }
        //nine特征字母'i'，减去five中的f(chCnt['f'] - chCnt['u']),six中的'x',eight中的g
        if (chCnt['i'] - (chCnt['f'] - chCnt['u']) - chCnt['x'] - chCnt['g'] > 0){
            result += string(chCnt['i'] - (chCnt['f'] - chCnt['u']) - chCnt['x'] - chCnt['g'], '9');
        }
        return result;
    }
};

```