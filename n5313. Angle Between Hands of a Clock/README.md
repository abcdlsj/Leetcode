# Angle Between Hands of a Clock **
- 题目地址: [https://leetcode-cn.com/problems/angle-between-hands-of-a-clock](https://leetcode-cn.com/problems/angle-between-hands-of-a-clock)
- 执行时间: 4 ms
- 内存消耗: 8.3 MB
- 通过日期: 2020-02-08 23:27

## 题目内容
<p>给你两个数 <code>hour</code> 和 <code>minutes</code> 。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。</p>



<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/08/sample_1_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 12, minutes = 30
<strong>输出：</strong>165
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/08/sample_2_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 3, minutes = 30
<strong>输出；</strong>75
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/08/sample_3_1673.png" style="height: 231px; width: 230px;"></strong></p>

<pre><strong>输入：</strong>hour = 3, minutes = 15
<strong>输出：</strong>7.5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>hour = 4, minutes = 50
<strong>输出：</strong>155
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>hour = 12, minutes = 0
<strong>输出：</strong>0
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= hour <= 12</code></li>
	<li><code>0 <= minutes <= 59</code></li>
	<li>与标准答案误差在 <code>10^-5</code> 以内的结果都被视为正确结果。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    double abs(double x){
      if(-x) return -x;
      else return x;
    }
    double angleClock(int hour, int minutes) {
      double h = (hour-12)*30+0.5*minutes;
      double m = minutes*6;
      double ans = abs(h-m) - floor(abs(h-m)/360)*360;
      if(ans > 180) return 360-ans;
      return ans;
    }
};

```