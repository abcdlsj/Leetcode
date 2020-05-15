# Student Attendance Record I *
- 题目地址: [https://leetcode-cn.com/problems/student-attendance-record-i](https://leetcode-cn.com/problems/student-attendance-record-i)
- 执行时间: 0 ms
- 内存消耗: 6.2 MB
- 通过日期: 2020-05-11 14:30

## 题目内容
<p>给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：</p>

<ol>
	<li><strong>'A'</strong> : Absent，缺勤</li>
	<li><strong>'L'</strong> : Late，迟到</li>
	<li><strong>'P'</strong> : Present，到场</li>
</ol>

<p>如果一个学生的出勤记录中不<strong>超过一个'A'(缺勤)</strong>并且<strong>不超过两个连续的'L'(迟到)</strong>,那么这个学生会被奖赏。</p>

<p>你需要根据这个学生的出勤记录判断他是否会被奖赏。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "PPALLP"
<strong>输出:</strong> True
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "PPALLL"
<strong>输出:</strong> False
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool checkRecord(string s) {
        return count(s.begin(), s.end(), 'A') < 2 && s.find("LLL") == -1;
    }
};

```