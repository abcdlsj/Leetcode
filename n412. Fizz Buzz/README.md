# Fizz Buzz *
- 题目地址: [https://leetcode-cn.com/problems/fizz-buzz](https://leetcode-cn.com/problems/fizz-buzz)
- 执行时间: 8 ms
- 内存消耗: 7.5 MB
- 通过日期: 2020-05-10 07:31

## 题目内容
<p>写一个程序，输出从 1 到 <em>n</em> 数字的字符串表示。</p>

<p>1. 如果 <em>n </em>是3的倍数，输出“Fizz”；</p>

<p>2. 如果 <em>n </em>是5的倍数，输出“Buzz”；</p>

<p>3.如果 <em>n </em>同时是3和5的倍数，输出 “FizzBuzz”。</p>

<p><strong>示例：</strong></p>

<pre>n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n, "");
        for(int i = 0; i < n; i++) {
            if((i + 1) % 3 == 0) {
                res[i] += "Fizz";
            }
            if((i + 1) % 5 == 0) {
                res[i] += "Buzz";
            } 
            if((i + 1) % 3 != 0 && (i + 1) % 5 != 0){
                res[i] += to_string(i + 1);
            } 
        }
        return res;
    }
};

```