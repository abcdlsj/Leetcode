# Container With Most Water **
- 题目地址: [https://leetcode-cn.com/problems/container-with-most-water](https://leetcode-cn.com/problems/container-with-most-water)
- 执行时间: 24 ms
- 内存消耗: 7.3 MB
- 通过日期: 2020-03-24 21:33

## 题目内容
<p>给你 <em>n</em> 个非负整数 <em>a</em><sub>1</sub>，<em>a</em><sub>2，</sub>...，<em>a</em><sub>n，</sub>每个数代表坐标中的一个点 (<em>i</em>, <em>a<sub>i</sub></em>) 。在坐标内画 <em>n</em> 条垂直线，垂直线 <em>i</em> 的两个端点分别为 (<em>i</em>, <em>a<sub>i</sub></em>) 和 (<em>i</em>, 0)。找出其中的两条线，使得它们与 <em>x</em> 轴共同构成的容器可以容纳最多的水。</p>

<p><strong>说明：</strong>你不能倾斜容器，且 <em>n</em> 的值至少为 2。</p>



<p><img alt="" src="https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg" style="height: 287px; width: 600px;"></p>

<p><small>图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。</small></p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[1,8,6,2,5,4,8,3,7]
<strong>输出：</strong>49</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
  public:
    int maxArea(vector<int>& height) {
      int MAX = 0, left = 0, right = height.size() - 1;
      while(left < right) {
        if(height[left] < height[right]) {
          MAX = max(MAX, height[left] * (right - left));
          left ++;
        }
        else {
          MAX = max(MAX, height[right] * (right - left));
          right --;
        }
      }
      return MAX;
    }
  };


```