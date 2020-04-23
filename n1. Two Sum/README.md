# Two Sum *
- 题目地址: [https://leetcode-cn.com/problems/two-sum](https://leetcode-cn.com/problems/two-sum)
- 执行时间: 12 ms
- 内存消耗: 8.2 MB
- 通过日期: 2020-03-24 21:24

## 题目内容
<p>给定一个整数数组 <code>nums</code> 和一个目标值 <code>target</code>，请你在该数组中找出和为目标值的那 <strong>两个</strong> 整数，并返回他们的数组下标。</p>

<p>你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。</p>



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
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end())
                return {map[target - nums[i]], i};
            else map[nums[i]] = i;
        }
        return {};
    }
};

```