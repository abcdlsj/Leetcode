# 打印从1到最大的n位数 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof)
- 执行时间: 4 ms
- 内存消耗: 11.4 MB
- 通过日期: 2020-04-13 08:49

## 题目内容
<p>输入数字 <code>n</code>，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> n = 1
<strong>输出:</strong> [1,2,3,4,5,6,7,8,9]
</pre>



<p>说明：</p>

<ul>
	<li>用返回一个整数列表来代替打印</li>
	<li>n 为正整数</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> printNumbers(int n) {
        int num = 0;
        for(int i = 0; i < n; i++) {
            num = num * 10;
            num += 9;
        }
        vector<int> res;
        for(int i = 1; i <= num; i++) {
            res.push_back(i);
        }
        return res;
    }
};

```