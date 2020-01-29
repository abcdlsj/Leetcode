# Hamming Distance *
- 题目地址: [https://leetcode-cn.com/problems/hamming-distance](https://leetcode-cn.com/problems/hamming-distance)
- 执行时间: 4 ms
- 内存消耗: 8.2 MB
- 通过日期: 2019-09-21 16:48

## 题目内容
<p>两个整数之间的<a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB">汉明距离</a>指的是这两个数字对应二进制位不同的位置的数目。</p>

<p>给出两个整数 <code>x</code> 和 <code>y</code>，计算它们之间的汉明距离。</p>

<p><strong>注意：</strong><br />
0 ≤ <code>x</code>, <code>y</code> < 2<sup>31</sup>.</p>

<p><strong>示例:</strong></p>

<pre>
<strong>输入:</strong> x = 1, y = 4

<strong>输出:</strong> 2

<strong>解释:</strong>
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset <32> bin(x^y);
        return bin.count();
    }
};

```