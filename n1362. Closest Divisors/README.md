# Closest Divisors **
- 题目地址: [https://leetcode-cn.com/problems/closest-divisors](https://leetcode-cn.com/problems/closest-divisors)
- 执行时间: 1496 ms
- 内存消耗: 376.8 MB
- 通过日期: 2020-02-25 17:35

## 题目内容
<p>给你一个整数 <code>num</code>，请你找出同时满足下面全部要求的两个整数：</p>

<ul>
	<li>两数乘积等于  <code>num + 1</code> 或 <code>num + 2</code></li>
	<li>以绝对差进行度量，两数大小最接近</li>
</ul>

<p>你可以按任意顺序返回这两个整数。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 8
<strong>输出：</strong>[3,3]
<strong>解释：</strong>对于 num + 1 = 9，最接近的两个因数是 3 & 3；对于 num + 2 = 10, 最接近的两个因数是 2 & 5，因此返回 3 & 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 123
<strong>输出：</strong>[5,25]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 999
<strong>输出：</strong>[40,25]
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= num <= 10^9</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> divisors(int num){
        vector<vector<int>> cnt;
        vector<int> tmp(2,0);
        for(int i = 1; i <= floor(sqrt(num)); ++i) {
            if(num%i==0) {
                tmp[0] = i;
                tmp[1] = num / i;
            }
                cnt.push_back(tmp);
        }
        return cnt;
    }
    vector<int> closestDivisors(int num) {
        vector<vector<int>> num1 = divisors(num+1);
        vector<vector<int>> num2 = divisors(num+2);
        int flag = 0;
        vector<int> ret;
        if((num1[num1.size()-1][1]-num1[num1.size()-1][0])>=(num2[num2.size()-1][1]-num2[num2.size()-1][0]))
        {
            ret.push_back(num2[num2.size()-1][1]);
            ret.push_back(num2[num2.size()-1][0]);
        }
        else{
            ret.push_back(num1[num1.size()-1][1]);
            ret.push_back(num1[num1.size()-1][0]); 
        }
 
        return ret;
    }   
};

```