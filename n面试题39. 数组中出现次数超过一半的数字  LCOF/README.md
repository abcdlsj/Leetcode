# 数组中出现次数超过一半的数字  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof)
- 执行时间: 40 ms
- 内存消耗: 18.7 MB
- 通过日期: 2020-04-13 15:00

## 题目内容
<p>数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。</p>



<p>你可以假设数组是非空的，并且给定的数组总是存在多数元素。</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1, 2, 3, 2, 2, 2, 5, 4, 2]
<strong>输出:</strong> 2</pre>



<p><strong>限制：</strong></p>

<p><code>1 <= 数组长度 <= 50000</code></p>



<p>注意：本题与主站 169 题相同：<a href="https://leetcode-cn.com/problems/majority-element/">https://leetcode-cn.com/problems/majority-element/</a></p>




## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for(auto num : nums) {
            if(cnt == 0) {
                res = num;
                cnt++;
            } else {
                res == num ? cnt++ : cnt--;
            }
        }
        return res;
    }
};

```