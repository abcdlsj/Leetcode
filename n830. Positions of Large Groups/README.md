# Positions of Large Groups *
- 题目地址: [https://leetcode-cn.com/problems/positions-of-large-groups](https://leetcode-cn.com/problems/positions-of-large-groups)
- 执行时间: 16 ms
- 内存消耗: 9.4 MB
- 通过日期: 2019-08-30 16:01

## 题目内容
<p>在一个由小写字母构成的字符串 <code>S</code> 中，包含由一些连续的相同字符所构成的分组。</p>

<p>例如，在字符串 <code>S = "abbxxxxzyy"</code> 中，就含有 <code>"a"</code>, <code>"bb"</code>, <code>"xxxx"</code>, <code>"z"</code> 和 <code>"yy"</code> 这样的一些分组。</p>

<p>我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。</p>

<p>最终结果按照字典顺序输出。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>"abbxxxxzzy"
<strong>输出: </strong>[[3,6]]
<strong>解释</strong>: <code>"xxxx" 是一个起始于 3 且终止于 6 的较大分组</code>。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>"abc"
<strong>输出: </strong>[]
<strong>解释</strong>: "a","b" 和 "c" 均不是符合要求的较大分组。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入: </strong>"abcdddeeeeaabbbcd"
<strong>输出: </strong>[[3,5],[6,9],[12,14]]</pre>

<p><strong>说明: </strong> <code>1 <= S.length <= 1000</code></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if(S.length()<3) return vector<vector<int>>();
        vector<vector<int>> ans;
        S+='A';
        int i=0,j=0,n=S.length();
        while(j<n)
        {
            if(S[j]==S[i])
                j++;
            else{
                if(j-i>=3)
                    ans.emplace_back(vector<int>{i,j-1});
                i=j;
            }
        }
        return ans;
    }
};

```