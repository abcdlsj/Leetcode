# Deep Dark Fraction *
- 题目地址: [https://leetcode-cn.com/problems/deep-dark-fraction](https://leetcode-cn.com/problems/deep-dark-fraction)
- 执行时间: 0 ms
- 内存消耗: 8.3 MB
- 通过日期: 2019-09-24 22:15

## 题目内容
<p>有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/09/fraction_example_1.jpg" style="height: 195px; width: 480px;"></p>

<p>连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。</p>



<p>输入的<code>cont</code>代表连分数的系数（<code>cont[0]</code>代表上图的<code>a<sub>0</sub></code>，以此类推）。返回一个长度为2的数组<code>[n, m]</code>，使得连分数的值等于<code>n / m</code>，且<code>n, m</code>最大公约数为1。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>cont = [3, 2, 0, 2]
<strong>输出：</strong>[13, 4]
<strong>解释：</strong>原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>cont = [0, 0, 3]
<strong>输出：</strong>[3, 1]
<strong>解释：</strong>如果答案是整数，令分母为1即可。</pre>

<p><strong>限制：</strong></p>

<ol>
	<li><code>cont[i] >= 0</code></li>
	<li><code>1 <= cont的长度 <= 10</code></li>
	<li><code>cont</code>最后一个元素不等于0</li>
	<li>答案的<code>n, m</code>的取值都能被32位int整型存下（即不超过<code>2 ^ 31 - 1</code>）。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> ans;
        int t=cont.size()-1;
        int n=0,m=1;
        for(int i=t;i>0;--i){
            n=n+cont[i]*m;
            swap(n,m);
        }
        n = cont[0]*m+n;
        ans.push_back(n);
        ans.push_back(m);
        return ans;
        
    }
};

```