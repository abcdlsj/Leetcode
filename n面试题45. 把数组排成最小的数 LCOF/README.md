# 把数组排成最小的数 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof)
- 执行时间: 20 ms
- 内存消耗: 11.8 MB
- 通过日期: 2020-05-06 13:38

## 题目内容
<p>输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>[10,2]</code>
<strong>输出:</strong> "<code>102"</code></pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <code>[3,30,34,5,9]</code>
<strong>输出:</strong> "<code>3033459"</code></pre>



<p><strong>提示:</strong></p>

<ul>
	<li><code>0 < nums.length <= 100</code></li>
</ul>

<p><strong>说明: </strong></p>

<ul>
	<li>输出结果可能非常大，所以你需要返回一个字符串而不是整数</li>
	<li>拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(auto num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), compare);
        for(auto s : strs) {
            res += s;
        }
        return res;
    }
    static bool compare(const string &a, const string &b) {
        return a + b < b + a;
    }
};

```