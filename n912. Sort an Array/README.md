# Sort an Array **
- 题目地址: [https://leetcode-cn.com/problems/sort-an-array](https://leetcode-cn.com/problems/sort-an-array)
- 执行时间: 208 ms
- 内存消耗: 96.4 MB
- 通过日期: 2020-03-04 10:10

## 题目内容
<p>给定一个整数数组 <code>nums</code>，将该数组升序排列。</p>



<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[5,2,3,1]
<strong>输出：</strong>[1,2,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[5,1,1,2,0,0]
<strong>输出：</strong>[0,0,1,1,2,5]
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= A.length <= 10000</code></li>
	<li><code>-50000 <= A[i] <= 50000</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void bubble_sort(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }
    void quick_sort(vector<int> &nums, int begin, int end) {
        while (begin >= end) return;
        int cpr = nums[end];
        int left = begin, right = end - 1;
        while(left < right) {
            while (left < right && nums[left] < cpr) ++left;
            while (left < right && nums[right] >= cpr) --right;
            swap(nums[left], nums[right]);
        }
        if(nums[left] >= nums[end])
            swap(nums[left], nums[end]);
        else ++left;
        quick_sort(nums, begin, left - 1);
        quick_sort(nums, left + 1, end);
    }
    void insertion_sort(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int tmp = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > tmp) {
                nums[j+1] = nums[j];
                j --;
            }
            nums[j+1] = tmp;
        }
    }
    //归并
    void merge(vector<int> &Array, int front, int mid, int end) {
        vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
        vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);

        int idxLeft = 0, idxRight = 0;
        LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
        RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());

        for(int i = front; i <= end; i++){
            if(LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
                Array[i] = LeftSubArray[idxLeft];
                idxLeft ++; 
            } else {
                Array[i] = RightSubArray[idxRight];
                idxRight ++;
            }
        }
    }

    void MergeSort(vector<int> &Array, int front, int end) {
        if(front >= end) return;
        int mid = front + (end - front) / 2;
        MergeSort(Array, front, mid);
        MergeSort(Array, mid + 1, end);
        merge(Array, front, mid, end); 
    }


    vector<int> sortArray(vector<int>& nums) {
        // quick_sort(nums, 0, nums.size() - 1);
        // bubble_sort(nums);
        // insertion_sort(nums);
        MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

```