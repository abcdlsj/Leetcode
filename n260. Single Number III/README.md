# Single Number III **
- 题目地址: [https://leetcode-cn.com/problems/single-number-iii](https://leetcode-cn.com/problems/single-number-iii)
- 执行时间: 1204 ms
- 内存消耗: 9.6 MB
- 通过日期: 2019-08-12 12:02

## 题目内容
<p>给定一个整数数组 <code>nums</code>，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。</p>

<p><strong>示例 :</strong></p>

<pre><strong>输入:</strong> <code>[1,2,1,3,2,5]</code>
<strong>输出:</strong> <code>[3,5]</code></pre>

<p><strong>注意：</strong></p>

<ol>
	<li>结果输出的顺序并不重要，对于上面的例子， <code>[5, 3]</code> 也是正确答案。</li>
	<li>你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        R0:
        for(vector<int>::iterator i=nums.begin();i!=nums.end()-1;i++){
            for(vector<int>::iterator j=i+1;j!=nums.end();j++){
                if(*i==*j){
                    nums.erase(j);
                    nums.erase(i);
                    goto R0;
                }
            }
        }
        return nums;
    }
};

```