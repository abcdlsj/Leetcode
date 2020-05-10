# Find Minimum in Rotated Sorted Array II ***
- 题目地址: [https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii)
- 执行时间: 20 ms
- 内存消耗: 12.4 MB
- 通过日期: 2020-05-03 21:51

## 题目内容
<p>假设按照升序排序的数组在预先未知的某个点上进行了旋转。</p>

<p>( 例如，数组 <code>[0,1,2,4,5,6,7]</code> <strong> </strong>可能变为 <code>[4,5,6,7,0,1,2]</code> )。</p>

<p>请找出其中最小的元素。</p>

<p>注意数组中可能存在重复的元素。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> [1,3,5]
<strong>输出:</strong> 1</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> [2,2,2,0,1]
<strong>输出:</strong> 0</pre>

<p><strong>说明：</strong></p>

<ul>
	<li>这道题是 <a href="https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/">寻找旋转排序数组中的最小值</a> 的延伸题目。</li>
	<li>允许重复会影响算法的时间复杂度吗？会如何影响，为什么？</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else if(nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return nums[left];
    }
};

```