# Majority Element 
- 题目地址: [https://leetcode-cn.com/problems/majority-element](https://leetcode-cn.com/problems/majority-element)
- 执行时间: 20 ms
- 内存消耗: 11 MB
- 通过日期: 2019-08-26 23:28

## 题目内容
<p>给定一个大小为 <em>n </em>的数组，找到其中的多数元素。多数元素是指在数组中出现次数<strong>大于</strong> <code>⌊ n/2 ⌋</code> 的元素。</p>

<p>你可以假设数组是非空的，并且给定的数组总是存在多数元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [3,2,3]
<strong>输出:</strong> 3</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [2,2,1,1,1,2,2]
<strong>输出:</strong> 2
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> re;
        int ans;
        for(int i=0;i<n;i++)
        {
            re[nums[i]]++;
            if(re[nums[i]]>(n/2))
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};

```