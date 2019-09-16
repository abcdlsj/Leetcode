# Range Sum Query - Immutable *
- 题目地址: [https://leetcode-cn.com/problems/range-sum-query-immutable](https://leetcode-cn.com/problems/range-sum-query-immutable)
- 执行时间: 76 ms 
- 内存消耗: 17.3 MB
- 通过日期: 2019-09-16 10:00

## 题目内容
<p>给定一个整数数组  <em>nums</em>，求出数组从索引 <em>i </em>到 <em>j  </em>(<em>i</em> ≤ <em>j</em>) 范围内元素的总和，包含 <em>i,  j </em>两点。</p>

<p><strong>示例：</strong></p>

<pre>给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3</pre>

<p><strong>说明:</strong></p>

<ol>
	<li>你可以假设数组不可变。</li>
	<li>会多次调用 <em>sumRange</em> 方法。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class NumArray {
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        int s=0;
        num.push_back(s);
        for(int i=0;i<nums.size();++i){
            s+=nums[i];
            num.push_back(s);
        }
    }
    
    int sumRange(int i, int j) {
        return num[j+1]-num[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

```