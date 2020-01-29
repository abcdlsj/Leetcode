# Powerful Integers *
- 题目地址: [https://leetcode-cn.com/problems/powerful-integers](https://leetcode-cn.com/problems/powerful-integers)
- 执行时间: 4 ms
- 内存消耗: 8.7 MB
- 通过日期: 2020-01-18 14:25

## 题目内容
<p>给定两个正整数 <code>x</code> 和 <code>y</code>，如果某一整数等于 <code>x^i + y^j</code>，其中整数 <code>i >= 0</code> 且 <code>j >= 0</code>，那么我们认为该整数是一个<em>强整数</em>。</p>

<p>返回值小于或等于 <code>bound</code> 的所有<em>强整数</em>组成的列表。</p>

<p>你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>x = 2, y = 3, bound = 10
<strong>输出：</strong>[2,3,4,5,7,9,10]
<strong>解释： </strong>
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>x = 3, y = 5, bound = 15
<strong>输出：</strong>[2,4,6,8,10,14]
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= x <= 100</code></li>
	<li><code>1 <= y <= 100</code></li>
	<li><code>0 <= bound <= 10^6</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> cnt;
        for (int a = 1;a < bound ; a *= x){
          for(int b = 1; a+b <= bound; b *= y)
          {
            cnt.push_back(a+b);
            if (y==1) break;
          }
          if(x==1) break; 
        }
        set<int> ans(cnt.begin(),cnt.end());
        cnt.assign(ans.begin(),ans.end());
        return cnt;
    }
};

```