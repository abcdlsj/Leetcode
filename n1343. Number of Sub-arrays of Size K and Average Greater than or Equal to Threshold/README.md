# Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold **
- 题目地址: [https://leetcode-cn.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold](https://leetcode-cn.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold)
- 执行时间: 104 ms
- 内存消耗: 16.5 MB
- 通过日期: 2020-02-09 10:49

## 题目内容
<p>给你一个整数数组 <code>arr</code> 和两个整数 <code>k</code> 和 <code>threshold</code> 。</p>

<p>请你返回长度为 <code>k</code> 且平均值大于等于 <code>threshold</code> 的子数组数目。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
<strong>输出：</strong>3
<strong>解释：</strong>子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,1,1,1,1], k = 1, threshold = 0
<strong>输出：</strong>5
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
<strong>输出：</strong>6
<strong>解释：</strong>前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
<strong>输出：</strong>1
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [4,4,4,4], k = 4, threshold = 1
<strong>输出：</strong>1
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10^5</code></li>
	<li><code>1 <= arr[i] <= 10^4</code></li>
	<li><code>1 <= k <= arr.length</code></li>
	<li><code>0 <= threshold <= 10^4</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      //滑动窗口，昨天没想到，导致时间复杂度爆了
      int n = arr.size(),sum = 0,ans = 0;
      threshold *= k;
      if(k > n) return 0;
      for(int i = 0; i < k; i++){
        sum += arr[i];
      }
      if(sum >= threshold) ans++;
      for(int i = k; i < n; i++){
        sum = sum - arr[i - k] + arr[i];
        if(sum >= threshold) ans++;
      }
      return ans;
    }
};

```