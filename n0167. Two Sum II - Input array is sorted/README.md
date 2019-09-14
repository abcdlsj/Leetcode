# Two Sum II - Input array is sorted *
- 题目地址: [https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted)
- 执行时间: 12 ms 
- 内存消耗: 9.6 MB
- 通过日期: 2019-09-13 20:40

## 题目内容
<p>给定一个已按照<strong><em>升序排列</em> </strong>的有序数组，找到两个数使得它们相加之和等于目标数。</p>

<p>函数应该返回这两个下标值<em> </em>index1 和 index2，其中 index1 必须小于 index2<em>。</em></p>

<p><strong>说明:</strong></p>

<ul>
	<li>返回的下标值（index1 和 index2）不是从零开始的。</li>
	<li>你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。</li>
</ul>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> numbers = [2, 7, 11, 15], target = 9
<strong>输出:</strong> [1,2]
<strong>解释:</strong> 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        vector<int> ans;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            if(sum < target) i++;
            else j--;
        }
        return ans;
    }
};

```