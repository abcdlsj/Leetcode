# Sub Sort LCCI **
- 题目地址: [https://leetcode-cn.com/problems/sub-sort-lcci](https://leetcode-cn.com/problems/sub-sort-lcci)
- 执行时间: 156 ms
- 内存消耗: 38.9 MB
- 通过日期: 2020-04-03 16:23

## 题目内容
<p>给定一个整数数组，编写一个函数，找出索引<code>m</code>和<code>n</code>，只要将索引区间<code>[m,n]</code>的元素排好序，整个数组就是有序的。注意：<code>n-m</code>尽量最小，也就是说，找出符合条件的最短序列。函数返回值为<code>[m,n]</code>，若不存在这样的<code>m</code>和<code>n</code>（例如整个数组是有序的），请返回<code>[-1,-1]</code>。</p>
<p><strong>示例：</strong></p>
<pre><strong>输入：</strong> [1,2,4,7,10,11,7,12,6,7,16,18,19]
<strong>输出：</strong> [3,9]
</pre>
<p><strong>提示：</strong></p>
<ul>
<li><code>0 <= len(array) <= 1000000</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if(array.size() == 0 || array.size() == 1) return {-1, -1};
        int MAX = INT_MIN, MIN = INT_MAX, right = -1, left = -1;
        //1,2,4, || 7,10,11,7,12,6,7, || 16,18,19
        for(int i = 0; i < array.size(); i++) {
            if(array[i] >= MAX) MAX = array[i];
            else right = i;
            if(array[array.size() - i - 1] <= MIN) MIN = array[array.size() - i - 1];
            else left = array.size() - i - 1;
        }
        return {left, right};
    }
};

```