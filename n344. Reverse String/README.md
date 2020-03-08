# Reverse String *
- 题目地址: [https://leetcode-cn.com/problems/reverse-string](https://leetcode-cn.com/problems/reverse-string)
- 执行时间: 56 ms
- 内存消耗: 15.3 MB
- 通过日期: 2020-03-07 14:59

## 题目内容
<p>编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 <code>char[]</code> 的形式给出。</p>

<p>不要给另外的数组分配额外的空间，你必须<strong><a href="https://baike.baidu.com/item/原地算法" target="_blank">原地</a>修改输入数组</strong>、使用 O(1) 的额外空间解决这一问题。</p>

<p>你可以假设数组中的所有字符都是 <a href="https://baike.baidu.com/item/ASCII" target="_blank">ASCII</a> 码表中的可打印字符。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>["h","e","l","l","o"]
<strong>输出：</strong>["o","l","l","e","h"]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>["H","a","n","n","a","h"]
<strong>输出：</strong>["h","a","n","n","a","H"]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0) return;
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return;
    }
};

```