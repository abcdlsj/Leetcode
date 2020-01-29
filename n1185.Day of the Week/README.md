# Day of the Week 
- 题目地址: [https://leetcode-cn.com/problems/day-of-the-week](https://leetcode-cn.com/problems/day-of-the-week)
- 执行时间: 8 ms
- 内存消耗: 8.1 MB
- 通过日期: 2019-09-08 11:31

## 题目内容
<p>给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。</p>

<p>输入为三个整数：<code>day</code>、<code>month</code> 和 <code>year</code>，分别表示日、月、年。</p>

<p>您返回的结果必须是这几个值中的一个 <code>{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}</code>。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>day = 31, month = 8, year = 2019
<strong>输出：</strong>"Saturday"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>day = 18, month = 7, year = 1999
<strong>输出：</strong>"Sunday"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>day = 15, month = 8, year = 1993
<strong>输出：</strong>"Sunday"
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li>给出的日期一定是在 <code>1971</code> 到 <code>2100</code> 年之间的有效日期。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string w[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string dayOfTheWeek(int day, int month, int year) {
        int d=0;
        for(int i=1971;i<year;i++)
        {
            if((i%4==0&&i%100!=0)||i%400==0)
            {
                d+= 366;
            }
            else
                d+= 365;
        
        }
        if((year%4==0&&year%100!=0)||year%400==0)
        {
            for(int i=0;i<month-1;i++)
                d+=b[i];
            d +=day;
        }
        else
        {
            for(int i=0;i<month-1;i++)
                d+=a[i];
            d = d+day;  
        }
        return w[(d+4)%7];
    }
};

```