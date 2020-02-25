# Number of Days Between Two Dates *
- 题目地址: [https://leetcode-cn.com/problems/number-of-days-between-two-dates](https://leetcode-cn.com/problems/number-of-days-between-two-dates)
- 执行时间: 4 ms
- 内存消耗: 8.3 MB
- 通过日期: 2020-02-25 13:43

## 题目内容
<p>请你编写一个程序来计算两个日期之间隔了多少天。</p>

<p>日期以字符串形式给出，格式为 <code>YYYY-MM-DD</code>，如示例所示。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>date1 = "2019-06-29", date2 = "2019-06-30"
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>date1 = "2020-01-15", date2 = "2019-12-31"
<strong>输出：</strong>15
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li>给定的日期是 <code>1971</code> 年到 <code>2100</code> 年之间的有效日期。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool runyear(int year){
        return ((year%4==0&&year%100!=0)||year%400==0);
    }
    int getdays(string s){
        int monthes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = 0,month = 0,day = 0;
        for(int i = 0; i < 4; i++)
            year = year*10+(s[i] - '0');
        month = 10*(int)(s[5] - '0')+ (int)(s[6] - '0');
        day = 10*(int)(s[8] - '0')+ (int)(s[9] - '0');
        if(runyear(year))
            monthes[1] = 29;
        for(int i = 0; i < month - 1; i++)
            day += monthes[i];
        for(int i = 1971; i < year; i++)
            day += runyear(i)?366:365;
        return day;
    }
    int daysBetweenDates(string date1, string date2) {
        return fabs(getdays(date1)-getdays(date2));
    }
};

```