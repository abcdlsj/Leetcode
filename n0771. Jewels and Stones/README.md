# Jewels and Stones *
- 题目地址: [https://leetcode-cn.com/problems/jewels-and-stones](https://leetcode-cn.com/problems/jewels-and-stones)
- 执行时间: 4 ms 
- 内存消耗: 8.3 MB
- 通过日期: 2019-09-18 11:04

## 题目内容
<p> 给定字符串<code>J</code> 代表石头中宝石的类型，和字符串 <code>S</code>代表你拥有的石头。 <code>S</code> 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。</p>

<p><code>J</code> 中的字母不重复，<code>J</code> 和 <code>S</code>中的所有字符都是字母。字母区分大小写，因此<code>"a"</code>和<code>"A"</code>是不同类型的石头。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> J = "aA", S = "aAAbbbb"
<strong>输出:</strong> 3
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> J = "z", S = "ZZ"
<strong>输出:</strong> 0
</pre>

<p><strong>注意:</strong></p>

<ul>
	<li><code>S</code> 和 <code>J</code> 最多含有50个字母。</li>
	<li> <code>J</code> 中的字符不重复。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n = J.size(),m=S.size(),ans=0;
        if(n==0||m==0) return 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(J[i]==S[j])
                    ans++;
            }
        }
        return ans;
    }
};

```