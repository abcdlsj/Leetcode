# Check If N and Its Double Exist *
- 题目地址: [https://leetcode-cn.com/problems/check-if-n-and-its-double-exist](https://leetcode-cn.com/problems/check-if-n-and-its-double-exist)
- 执行时间: 8 ms
- 内存消耗: 8.9 MB
- 通过日期: 2020-02-09 11:13

## 题目内容
<p>给你一个整数数组 <code>arr</code>，请你检查是否存在两个整数 <code>N</code> 和 <code>M</code>，满足 <code>N</code> 是 <code>M</code> 的两倍（即，<code>N = 2 * M</code>）。</p>

<p>更正式地，检查是否存在两个下标 <code>i</code> 和 <code>j</code> 满足：</p>

<ul>
	<li><code>i != j</code></li>
	<li><code>0 <= i, j < arr.length</code></li>
	<li><code>arr[i] == 2 * arr[j]</code></li>
</ul>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [10,2,5,3]
<strong>输出：</strong>true
<strong>解释：</strong>N<code> = 10</code> 是 M<code> = 5 的两倍</code>，即 <code>10 = 2 * 5 。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [7,1,14,11]
<strong>输出：</strong>true
<strong>解释：</strong>N<code> = 14</code> 是 M<code> = 7 的两倍</code>，即 <code>14 = 2 * 7 </code>。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [3,1,7,11]
<strong>输出：</strong>false
<strong>解释：</strong>在该情况下不存在 N 和 M 满足 N = 2 * M 。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= arr.length <= 500</code></li>
	<li><code>-10^3 <= arr[i] <= 10^3</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      int n = arr.size();
      for(int i = 0;i < n ;i++){
        for(int j = 0;j < n;j++){
          if(i == j) continue;
          else if(arr[i]*2 == arr[j]) return true;
        }
      }
      return false;
    }
};

```