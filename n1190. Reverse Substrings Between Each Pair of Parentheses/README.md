# Reverse Substrings Between Each Pair of Parentheses **
- 题目地址: [https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses](https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses)
- 执行时间: 0 ms 
- 内存消耗: 9.4 MB
- 通过日期: 2019-09-15 15:11

## 题目内容
<p>给出一个字符串 <code>s</code>（仅含有小写英文字母和括号）。</p>

<p>请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。</p>

<p>注意，您的结果中 <strong>不应</strong> 包含任何括号。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "(abcd)"
<strong>输出：</strong>"dcba"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "(u(love)i)"
<strong>输出：</strong>"iloveu"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "(ed(et(oc))el)"
<strong>输出：</strong>"leetcode"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "a(bcdefghijkl(mno)p)q"
<strong>输出：</strong>"apmnolkjihgfedcbq"
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= s.length <= 2000</code></li>
	<li><code>s</code> 中只有小写英文字母和括号</li>
	<li>我们确保所有括号都是成对出现的</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        string ns="";
        string nns="";
        for(auto c : s){
            if(c=='(')
                st.push("");
            else if(c==')')
            {
                ns=st.top();st.pop();
                reverse(ns.begin(),ns.end());
                nns=st.top();st.pop();
                st.push(nns+ns);
            }
            else {
                ns=st.top();st.pop();
                st.push(ns+c);
            }
        }
        string ans;
        if(!st.empty()){
            ans = ans+st.top();st.pop();
        }
        return ans;
        
    }
};

```