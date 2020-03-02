# Two Sum *
- 题目地址: [https://leetcode-cn.com/problems/two-sum](https://leetcode-cn.com/problems/two-sum)
- 执行时间: 532 ms
- 内存消耗: 9.1 MB
- 通过日期: 2019-09-14 13:16

## 题目内容
<p>给定一个整数数组 <code>nums</code> 和一个目标值 <code>target</code>，请你在该数组中找出和为目标值的那 <strong>两个</strong> 整数，并返回他们的数组下标。</p>

<p>你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。</p>

<p><strong>示例:</strong></p>

<pre>给定 nums = [2, 7, 11, 15], target = 9

因为 nums[<strong>0</strong>] + nums[<strong>1</strong>] = 2 + 7 = 9
所以返回 [<strong>0, 1</strong>]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

```