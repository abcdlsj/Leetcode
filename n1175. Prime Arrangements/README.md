# Prime Arrangements *
- 题目地址: [https://leetcode-cn.com/problems/prime-arrangements](https://leetcode-cn.com/problems/prime-arrangements)
- 执行时间: 4 ms 
- 内存消耗: 8.1 MB
- 通过日期: 2019-09-01 20:52

## 题目内容
<p>请你帮忙给从 <code>1</code> 到 <code>n</code> 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。</p>

<p>让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。</p>

<p>由于答案可能会很大，所以请你返回答案 <strong>模 mod <code>10^9 + 7</code></strong> 之后的结果即可。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>12
<strong>解释：</strong>举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 100
<strong>输出：</strong>682289015
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 100</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    const long long mod=1e9+7;
    long long get(int n)
    {
        long long sum=1;
        for(int i=2;i<=n;i++)
            sum=i*sum%mod;
        return sum;
    }
    int getprime(int n)
    {
        vector<bool> elds(n+1,true);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(elds[i])
            {
                ans++;
                for(int j=2*i;j<=n;j+=i)
                    elds[j]=false;
            }
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        int ans = getprime(n);
        return get(ans)*get(n-ans)%mod;
    }
};

```