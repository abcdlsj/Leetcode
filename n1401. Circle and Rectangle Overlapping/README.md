# Circle and Rectangle Overlapping **
- 题目地址: [https://leetcode-cn.com/problems/circle-and-rectangle-overlapping](https://leetcode-cn.com/problems/circle-and-rectangle-overlapping)
- 执行时间: 0 ms
- 内存消耗: 6.2 MB
- 通过日期: 2020-04-05 09:52

## 题目内容
<p>给你一个以 (<code>radius</code>, <code>x_center</code>, <code>y_center</code>) 表示的圆和一个与坐标轴平行的矩形 (<code>x1</code>, <code>y1</code>, <code>x2</code>, <code>y2</code>)，其中 (<code>x1</code>, <code>y1</code>) 是矩形左下角的坐标，(<code>x2</code>, <code>y2</code>) 是右上角的坐标。</p>

<p>如果圆和矩形有重叠的部分，请你返回 True ，否则返回 False 。</p>

<p>换句话说，请你检测是否 <strong>存在</strong> 点 (xi, yi) ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。</p>



<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_4_1728.png" style="height: 167px; width: 258px;"></p>

<pre><strong>输入：</strong>radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
<strong>输出：</strong>true
<strong>解释：</strong>圆和矩形有公共点 (1,0) 
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_2_1728.png" style="height: 135px; width: 150px;"></strong></p>

<pre><strong>输入：</strong>radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_6_1728.png" style="height: 165px; width: 175px;"></strong></p>

<pre><strong>输入：</strong>radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
<strong>输出：</strong>false
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= radius <= 2000</code></li>
	<li><code>-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4</code></li>
	<li><code>x1 < x2</code></li>
	<li><code>y1 < y2</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double rectCenterX = (x2 + x1) / 2.0;
        double rectCenterY = (y2 + y1) / 2.0;

        vector<double> circleCenter2rectCenter = {abs(x_center - rectCenterX), abs(y_center - rectCenterY)};
        vector<double> vertex2rectCenter = {x2 - rectCenterX, y2 - rectCenterY};

        double vecX = max(circleCenter2rectCenter[0] - vertex2rectCenter[0], 0.0);
        double vecY = max(circleCenter2rectCenter[1] - vertex2rectCenter[1], 0.0);

        return sqrt(vecX * vecX + vecY * vecY) <= radius;
    }
};

```