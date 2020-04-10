# Sort Integers by The Power Value **
- 题目地址: [https://leetcode-cn.com/problems/sort-integers-by-the-power-value](https://leetcode-cn.com/problems/sort-integers-by-the-power-value)
- 执行时间: 384 ms
- 内存消耗: 8.9 MB
- 通过日期: 2020-03-21 23:51

## 题目内容
<p>我们将整数 <code>x</code> 的 <strong>权重</strong> 定义为按照下述规则将 <code>x</code> 变成 <code>1</code> 所需要的步数：</p>

<ul>
	<li>如果 <code>x</code> 是偶数，那么 <code>x = x / 2</code></li>
	<li>如果 <code>x</code> 是奇数，那么 <code>x = 3 * x + 1</code></li>
</ul>

<p>比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）。</p>

<p>给你三个整数 <code>lo</code>， <code>hi</code> 和 <code>k</code> 。你的任务是将区间 <code>[lo, hi]</code> 之间的整数按照它们的权重 <strong>升序排序 </strong>，如果大于等于 2 个整数有 <strong>相同</strong> 的权重，那么按照数字自身的数值 <strong>升序排序</strong> 。</p>

<p>请你返回区间 <code>[lo, hi]</code> 之间的整数按权重排序后的第 <code>k</code> 个数。</p>

<p>注意，题目保证对于任意整数 <code>x</code> <code>（lo <= x <= hi）</code> ，它变成 <code>1</code> 所需要的步数是一个 32 位有符号整数。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>lo = 12, hi = 15, k = 2
<strong>输出：</strong>13
<strong>解释：</strong>12 的权重为 9（12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）
13 的权重为 9
14 的权重为 17
15 的权重为 17
区间内的数按权重排序以后的结果为 [12,13,14,15] 。对于 k = 2 ，答案是第二个整数也就是 13 。
注意，12 和 13 有相同的权重，所以我们按照它们本身升序排序。14 和 15 同理。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>lo = 1, hi = 1, k = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>lo = 7, hi = 11, k = 4
<strong>输出：</strong>7
<strong>解释：</strong>区间内整数 [7, 8, 9, 10, 11] 对应的权重为 [16, 3, 19, 6, 14] 。
按权重排序后得到的结果为 [8, 10, 11, 7, 9] 。
排序后数组中第 4 个数字为 7 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>lo = 10, hi = 20, k = 5
<strong>输出：</strong>13
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>lo = 1, hi = 1000, k = 777
<strong>输出：</strong>570
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= lo <= hi <= 1000</code></li>
	<li><code>1 <= k <= hi - lo + 1</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    static int nums(int x) {
        int cnt = 0;
        while(x != 1) {
            if(x % 2 == 0) x /= 2;
            else x = x*3 + 1;
            cnt ++;
        }
        return cnt;
    }
    static bool cpr(int i, int j) {
        if(i == j) return i <= j ? true:false;
        else if(nums(i) == nums(j)) return i <= j ? true:false;
        else {
            return nums(i) < nums(j) ? true:false;
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<int> cnt;
        for(int i = lo; i <= hi; i++) cnt.push_back(i);
        sort(cnt.begin(), cnt.end(), cpr);
        for(int i = 0; i < cnt.size(); i++) cout << cnt[i] << " ";
        for(int i = 0; i < k; i++) {
            while(i == k - 1) return cnt[i];
        }
        return 0;
    }
};

```