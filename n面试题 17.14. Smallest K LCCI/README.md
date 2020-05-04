# Smallest K LCCI **
- 题目地址: [https://leetcode-cn.com/problems/smallest-k-lcci](https://leetcode-cn.com/problems/smallest-k-lcci)
- 执行时间: 80 ms
- 内存消耗: 18.4 MB
- 通过日期: 2020-04-30 22:12

## 题目内容
<p>设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong> arr = [1,3,5,7,2,4,6,8], k = 4
<strong>输出：</strong> [1,2,3,4]
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= len(arr) <= 100000</code></li>
	<li><code>0 <= k <= min(100000, len(arr))</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size(), end = n - 1;
        vector<int> res;
        for(int i = n / 2; i >= 0; i--) sink(arr, i, n - 1);
        while(k--) {
            res.push_back(arr[0]);
            swap(arr[0], arr[end--]);
            sink(arr, 0, end);
        }
        return res;
    }
    void sink(vector<int> &arr, int index, int end) {
        int sltIdx = index, left = index * 2 + 1, right = index * 2 + 2;

        if(left <= end && arr[left] < arr[sltIdx]) sltIdx = left;
        if(right <= end && arr[right] < arr[sltIdx]) sltIdx = right;

        if(sltIdx != index) {
            swap(arr[index], arr[sltIdx]);
            sink(arr, sltIdx, end);
        }
    }
};

```