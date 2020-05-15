# Sort an Array **
- 题目地址: [https://leetcode-cn.com/problems/sort-an-array](https://leetcode-cn.com/problems/sort-an-array)
- 执行时间: 40 ms
- 内存消耗: 15.7 MB
- 通过日期: 2020-05-07 10:06

## 题目内容
<p>给你一个整数数组 <code>nums</code>，请你将该数组升序排列。</p>



<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [5,2,3,1]
<strong>输出：</strong>[1,2,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,1,1,2,0,0]
<strong>输出：</strong>[0,0,1,1,2,5]
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= nums.length <= 50000</code></li>
	<li><code>-50000 <= nums[i] <= 50000</code></li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    //冒泡排序
    void bubble_sort(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }
    //快排
    int partition(vector<int> &nums, int begin, int end) {
        int cpr = nums[end], left = begin, right = end - 1;
        while(left < right) {
            while (left < right && nums[left] < cpr) ++left;
            while (left < right && nums[right] >= cpr) --right;
            swap(nums[left], nums[right]);
        }
        if(nums[left] >= nums[end]) {
            swap(nums[left], nums[end]);
        } else {
            ++left;
        }
        return left;
    }

    void quick_sort(vector<int> &nums, int begin, int end) {
        if(begin >= end) return;
        int p = partition(nums, begin, end);
        if(p > begin) quick_sort(nums, begin, p - 1);
        if(p < end) quick_sort(nums, p + 1, end); 
    }
    //非递归快排
    void iter_quick_sort(vector<int> &nums, int begin, int end) {
        stack<int> stack;
        stack.push(end);
        stack.push(begin);
        int left, right;
        while(!stack.empty()) {
            left = stack.top(); stack.pop();
            right = stack.top(); stack.pop();
            if(left < right) {
                int p = partition(nums, left, right);
                if(p > left) {
                    stack.push(p - 1);
                    stack.push(left);
                }
                if(p < right) {
                    stack.push(right);
                    stack.push(p + 1);
                }
            }
        }
    }
    //插入
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
    // 希尔排序
    void ShellSort(vector<int> &nums,int n) {    
    }

    //选择
    void selection_sort(vector<int> &nums) {
        int n = nums.size();
        int min;
        for(int i = 0; i < n - 1; i++) {
            min = i;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[min]) min = j;
            }
            swap(nums[i], nums[min]);
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
        iter_quick_sort(nums, 0, nums.size() - 1);
        // bubble_sort(nums);
        // insertion_sort(nums);
        // MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

```