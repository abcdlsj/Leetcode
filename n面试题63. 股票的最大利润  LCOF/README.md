# 股票的最大利润  LCOF **
- 题目地址: [https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof)
- 执行时间: 12 ms
- 内存消耗: 12.7 MB
- 通过日期: 2020-04-27 20:26

## 题目内容
<p>假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？</p>



<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [7,1,5,3,6,4]
<strong>输出:</strong> 5
<strong>解释: </strong>在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [7,6,4,3,1]
<strong>输出:</strong> 0
<strong>解释: </strong>在这种情况下, 没有交易完成, 所以最大利润为 0。</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= 数组长度 <= 10^5</code></p>



<p><strong>注意：</strong>本题与主站 121 题相同：<a href="https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/">https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minprice = prices[0], maxprofit = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }

        return maxprofit;
    }
};

```