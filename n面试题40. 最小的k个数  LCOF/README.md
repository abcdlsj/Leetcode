# 最小的k个数  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof)
- 执行时间: 64 ms
- 内存消耗: 19.1 MB
- 通过日期: 2020-05-07 00:41

## 题目内容
<p>输入整数数组 <code>arr</code> ，找出其中最小的 <code>k</code> 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,1], k = 2
<strong>输出：</strong>[1,2] 或者 [2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [0,1,2,1], k = 1
<strong>输出：</strong>[0]</pre>



<p><strong>限制：</strong></p>

<ul>
	<li><code>0 <= k <= arr.length <= 10000</code></li>
	<li><code>0 <= arr[i] <= 10000</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() == 0 || k == 0) return {};
        if(arr.size() == k) return arr;
        int n = arr.size(); vector<int> res;
        for(int index = (n - 1) / 2; index >= 0; index--) sink(arr, index, n);
        while(k--) {
            res.push_back(arr[0]);
            swap(arr[0], arr[--n]);
            sink(arr, 0, n);
        }
        return res;
    }
    void sink(vector<int> &arr, int index, int end) {
        int sIdx = index, left = index * 2 + 1, right = index * 2 + 2;

        if(left < end && arr[left] < arr[sIdx]) sIdx = left;
        if(right < end && arr[right] < arr[sIdx]) sIdx = right;

        if(sIdx != index) {
            swap(arr[sIdx], arr[index]);
            sink(arr, sIdx, end);
        }  
    }
};

```