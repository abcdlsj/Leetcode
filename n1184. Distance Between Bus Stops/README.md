# Distance Between Bus Stops *
- 题目地址: [https://leetcode-cn.com/problems/distance-between-bus-stops](https://leetcode-cn.com/problems/distance-between-bus-stops)
- 执行时间: 16 ms
- 内存消耗: 9 MB
- 通过日期: 2019-09-08 10:47

## 题目内容
<p>环形公交路线上有 <code>n</code> 个站，按次序从 <code>0</code> 到 <code>n - 1</code> 进行编号。我们已知每一对相邻公交站之间的距离，<code>distance[i]</code> 表示编号为 <code>i</code> 的车站和编号为 <code>(i + 1) % n</code> 的车站之间的距离。</p>

<p>环线上的公交车都可以按顺时针和逆时针的方向行驶。</p>

<p>返回乘客从出发点 <code>start</code> 到目的地 <code>destination</code> 之间的最短距离。</p>



<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1.jpg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 1
<strong>输出：</strong>1
<strong>解释：</strong>公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。</pre>



<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1-1.jpg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 2
<strong>输出：</strong>3
<strong>解释：</strong>公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。
</pre>



<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1-2.jpg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 3
<strong>输出：</strong>4
<strong>解释：</strong>公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10^4</code></li>
	<li><code>distance.length == n</code></li>
	<li><code>0 <= start, destination < n</code></li>
	<li><code>0 <= distance[i] <= 10^4</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size(),a=0,b=0;
        if(start==destination) return 0;
        if(start<destination){
            for(int i=start;i<destination;i++)
                a+=distance[i];
        }
        if(start>destination)
            for(int i=start-1;i>=destination;i--)
                a+=distance[i];
        for(int i=0;i<n;i++)
            b+=distance[i];
        if(2*a<=b)
            return a;
        else return b-a;
    }
};

```