# Count Primes *
- 题目地址: [https://leetcode-cn.com/problems/count-primes](https://leetcode-cn.com/problems/count-primes)
- 执行时间: 240 ms
- 内存消耗: 6.4 MB
- 通过日期: 2020-04-16 20:53

## 题目内容
<p>统计所有小于非负整数 <em>n </em>的质数的数量。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> 4
<strong>解释:</strong> 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> cnt(n, true);
        int ans = 0;
        for(int i = 2; i < n; i++) {
            if(cnt[i]) {
                ans++;
                for(int j = i + i; j < n; j += i) {
                    cnt[j] = false;
                }
            }
        }
        return ans;
    }
};

```