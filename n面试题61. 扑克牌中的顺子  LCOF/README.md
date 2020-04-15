# 扑克牌中的顺子  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof)
- 执行时间: 0 ms
- 内存消耗: 10.3 MB
- 通过日期: 2020-04-14 21:32

## 题目内容
<p>从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,2,3,4,5]
<strong>输出:</strong> True</pre>



<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [0,0,1,2,5]
<strong>输出:</strong> True</pre>



<p><strong>限制：</strong></p>

<p>数组长度为 5 </p>

<p>数组的数取值为 [0, 13] .</p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int cnt = 0, maxnum = INT_MIN, minnum = INT_MAX;
        set<int> set;
        for(auto num : nums) {
            if(num == 0) {
                cnt++;
            } else {
                if(set.find(num) == set.end()) {
                    maxnum = max(maxnum, num);
                    minnum = min(minnum, num);
                    set.insert(num);  
                } else {
                    return false;
                }
            }
        }
        if(cnt == 0) {
            return (maxnum - minnum) == 4;
        } else {
            return (maxnum - minnum) <= 4;
        }
    }
};

```