# Sorted Merge LCCI *
- 题目地址: [https://leetcode-cn.com/problems/sorted-merge-lcci](https://leetcode-cn.com/problems/sorted-merge-lcci)
- 执行时间: 4 ms
- 内存消耗: 11.7 MB
- 通过日期: 2020-03-03 11:30

## 题目内容
<p>给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。</p>

<p>初始化 A 和 B 的元素数量分别为 <em>m</em> 和 <em>n</em>。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

<strong>输出:</strong> [1,2,2,3,5,6]</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while(i >= 0 && j >= 0) {
            if(A[i] >= B[j]) 
                A[index--] = A[i--];
            else 
                A[index--] = B[j--]; 
        }
        while(j >=0) A[index--] = B[j--];
    }
}; 

```