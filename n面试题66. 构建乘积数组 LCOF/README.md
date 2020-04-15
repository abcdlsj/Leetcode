# 构建乘积数组 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof)
- 执行时间: 72 ms
- 内存消耗: 24.4 MB
- 通过日期: 2020-04-14 22:19

## 题目内容
<p>给定一个数组 <code>A[0,1,…,n-1]</code>，请构建一个数组 <code>B[0,1,…,n-1]</code>，其中 <code>B</code> 中的元素 <code>B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]</code>。不能使用除法。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,2,3,4,5]
<strong>输出:</strong> [120,60,40,30,24]</pre>



<p><strong>提示：</strong></p>

<ul>
	<li>所有元素乘积之和不会溢出 32 位整数</li>
	<li><code>a.length <= 100000</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size(), 0);
        for(int i = 0, left = 1; i < a.size(); left *= a[i], i++) {
            res[i] = left;
        }
        for(int i = a.size() - 1, right = 1; i >= 0; right *= a[i], i--) {
            res[i] *= right;
        }
        return res;
    }
};

```