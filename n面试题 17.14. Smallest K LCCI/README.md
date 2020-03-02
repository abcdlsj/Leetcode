# Smallest K LCCI **
- 题目地址: [https://leetcode-cn.com/problems/smallest-k-lcci](https://leetcode-cn.com/problems/smallest-k-lcci)
- 执行时间: 84 ms
- 内存消耗: 21.7 MB
- 通过日期: 2020-03-02 11:34

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
    // int quicksort(vector<int> &arr, int begin, int end) {
        // int cpr = arr[end];
        // int left = begin, right = end - 1;
        // while(left < right) {
            // while(left < right && arr[left] < cpr) left ++;
            // while(left < right && arr[right] >= cpr) right --;
            // swap(arr[left],arr[right]);
        // }
        // swap(arr[left],arr[end]);
        // return left; 
    // }
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
    vector<int> smallestK(vector<int>& arr, int k) {
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