# Edit Distance ***
- 题目地址: [https://leetcode-cn.com/problems/edit-distance](https://leetcode-cn.com/problems/edit-distance)
- 执行时间: 20 ms
- 内存消耗: 9.2 MB
- 通过日期: 2020-04-06 18:23

## 题目内容
<p>给你两个单词 <em>word1</em> 和 <em>word2</em>，请你计算出将 <em>word1</em> 转换成 <em>word2 </em>所使用的最少操作数 。</p>

<p>你可以对一个单词进行如下三种操作：</p>

<ol>
	<li>插入一个字符</li>
	<li>删除一个字符</li>
	<li>替换一个字符</li>
</ol>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word1 = "horse", word2 = "ros"
<strong>输出：</strong>3
<strong>解释：</strong>
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word1 = "intention", word2 = "execution"
<strong>输出：</strong>5
<strong>解释：</strong>
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        //dp[i][j]表示word1的前i个字母转换成word2的前j个字母所使用的最少操作。
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }  
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

```