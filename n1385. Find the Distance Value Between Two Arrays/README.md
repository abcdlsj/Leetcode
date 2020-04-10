# Find the Distance Value Between Two Arrays *
- 题目地址: [https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays](https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays)
- 执行时间: 12 ms
- 内存消耗: 8.2 MB
- 通过日期: 2020-03-21 23:35

## 题目内容
<p>给你两个整数数组 <code>arr1</code> ， <code>arr2</code> 和一个整数 <code>d</code> ，请你返回两个数组之间的 <strong>距离值</strong> 。</p>

<p>「<strong>距离值</strong>」<strong> </strong>定义为符合此描述的元素数目：对于元素 <code>arr1[i]</code> ，不存在任何元素 <code>arr2[j]</code> 满足 <code>|arr1[i]-arr2[j]| <= d</code> 。</p>



<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
<strong>输出：</strong>2
<strong>解释：</strong>
对于 arr1[0]=4 我们有：
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
对于 arr1[1]=5 我们有：
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
对于 arr1[2]=8 我们有：
<strong>|8-10|=2 <= d=2</strong>
<strong>|8-9|=1 <= d=2</strong>
|8-1|=7 > d=2
<strong>|8-8|=0 <= d=2</strong>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
<strong>输出：</strong>1
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr1.length, arr2.length <= 500</code></li>
	<li><code>-10^3 <= arr1[i], arr2[j] <= 10^3</code></li>
	<li><code>0 <= d <= 100</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int abs(int x) {
        if(x < 0) return -x;
        return x;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = arr1.size();
        if(d == 0) return ans;
        for(int i = 0; i < arr1.size(); i++) {
            for(int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    ans--;
                    break;
                } 
            }
        }
        return ans;
    }
};

```