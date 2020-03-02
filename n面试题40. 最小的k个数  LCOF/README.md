# 最小的k个数  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof)
- 执行时间: 60 ms
- 内存消耗: 21.9 MB
- 通过日期: 2020-03-02 11:36

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
    int partition(vector<int> &arr, int begin, int end) {
        int cpr = arr[end];
        int left = begin - 1, right = begin;
        for(; right < end; ++right) {
            if(arr[right] <= cpr) {
                ++ left;
                swap(arr[left], arr[right]);
            }
        }
        swap(arr[left+1], arr[end]);
        return left+1; 
    }
    void quick_sort(vector<int> &arr,int left,int right,int k) {
        if(left < right && left < k){
            int p = partition(arr, left, right);
            quick_sort(arr, left, p-1, k);
            if(p < k)
            {
                quick_sort(arr, p+1, right, k);
            }   
        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0) return res;
        if(arr.size() == k) return arr;
        quick_sort(arr, 0, arr.size() - 1, k);
        for(int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};

```