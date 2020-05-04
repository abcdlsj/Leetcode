# 最小的k个数  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof)
- 执行时间: 64 ms
- 内存消耗: 19.2 MB
- 通过日期: 2020-05-01 10:56

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
		int n = arr.size(); vector<int> res;
        if(n == 0 || k == 0 || k > n) return res;
        if(k == n) return arr;
        for(int i = (n - 1) / 2; i >= 0; i--) sink(arr, i, n);
        while(k--) {
            res.push_back(arr[0]);
            swap(arr[0], arr[n - 1]);
            sink(arr, 0, --n);
        }
        return res;
    }
    // 小顶堆
    void sink(vector<int> &arr, int index, int end) {
        int leastIdx = index, left = index * 2 + 1, right = index * 2 + 2;

        if(left < end && arr[leastIdx] > arr[left]) leastIdx = left;
        if(right < end && arr[leastIdx] > arr[right]) leastIdx = right;
        
        if(leastIdx != index) {
            swap(arr[leastIdx], arr[index]);
            sink(arr, leastIdx, end);
        }
    }
};

```