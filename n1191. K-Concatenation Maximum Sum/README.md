# K-Concatenation Maximum Sum **
- 题目地址: [https://leetcode-cn.com/problems/k-concatenation-maximum-sum](https://leetcode-cn.com/problems/k-concatenation-maximum-sum)
- 执行时间: 104 ms 
- 内存消耗: 14.1 MB
- 通过日期: 2019-09-15 16:11

## 题目内容
<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>k</code>。</p>

<p>首先，我们要对该数组进行修改，即把原数组 <code>arr</code> 重复 <code>k</code> 次。</p>

<blockquote>
<p>举个例子，如果 <code>arr = [1, 2]</code> 且 <code>k = 3</code>，那么修改后的数组就是 <code>[1, 2, 1, 2, 1, 2]</code>。</p>
</blockquote>

<p>然后，请你返回修改后的数组中的最大的子数组之和。</p>

<p>注意，子数组长度可以是 <code>0</code>，在这种情况下它的总和也是 <code>0</code>。</p>

<p>由于 <strong>结果可能会很大</strong>，所以需要 <strong>模（mod）</strong> <code>10^9 + 7</code> 后再返回。 </p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,2], k = 3
<strong>输出：</strong>9
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,-2,1], k = 5
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [-1,-2], k = 7
<strong>输出：</strong>0
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10^5</code></li>
	<li><code>1 <= k <= 10^5</code></li>
	<li><code>-10^4 <= arr[i] <= 10^4</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    typedef long long LL;
    LL MO = 1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        LL sum = 0,ans=0;
        for(auto n:arr) sum+=n;
        LL lmx=0,rmx=0,nmx=0,nnmx=0;
        //nnmx 是单数组最大子数组 lmx 是左最大 rmx 右最大 nmx 是过程量；
        for(int i=0;i<arr.size();i++){
            nmx=max(nmx+arr[i],(LL)arr[i]);
            nnmx=max(nnmx,nmx);
        }
        nmx=0;
        for(int i=0;i<arr.size();++i){
            nmx+=arr[i];
            lmx=max(lmx,nmx);
        }
        nmx=0;
        for(int i=arr.size()-1;i>=0;--i){
            nmx+=arr[i];
            rmx=max(rmx,nmx);
        }
        if(k==1) return nnmx%MO;
        else {
            ans = max(nnmx,max(lmx+rmx,lmx+rmx+(k-2)*sum));
            return ans%MO;
        }
        
        return ans%MO;
    }
};

```