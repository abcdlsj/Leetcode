# Diet Plan Performance *
- 题目地址: [https://leetcode-cn.com/problems/diet-plan-performance](https://leetcode-cn.com/problems/diet-plan-performance)
- 执行时间: 272 ms 
- 内存消耗: 9.3 MB
- 通过日期: 2019-09-01 20:53

## 题目内容
<p>你的好友是一位健身爱好者。前段日子，他给自己制定了一份健身计划。现在想请你帮他评估一下这份计划是否合理。</p>

<p>他会有一份计划消耗的卡路里表，其中 <code>calories[i]</code> 给出了你的这位好友在第 <code>i</code> 天需要消耗的卡路里总量。</p>

<p>为了更好地评估这份计划，对于卡路里表中的每一天，你都需要计算他 「这一天以及之后的连续几天」 （共 <code>k</code> 天）内消耗的总卡路里 <em>T：</em></p>

<ul>
	<li>如果 <code>T < lower</code>，那么这份计划相对糟糕，并失去 1 分； </li>
	<li>如果 <code>T > upper</code>，那么这份计划相对优秀，并获得 1 分；</li>
	<li>否则，这份计划普普通通，分值不做变动。</li>
</ul>

<p>请返回统计完所有 <code>calories.length</code> 天后得到的总分作为评估结果。</p>

<p>注意：总分可能是负数。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
<strong>输出：</strong>0
<strong>解释：</strong>calories[0], calories[1] < lower 而 calories[3], calories[4] > upper, 总分 = 0.</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>calories = [3,2], k = 2, lower = 0, upper = 1
<strong>输出：</strong>1
<strong>解释：</strong>calories[0] + calories[1] > upper, 总分 = 1.
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>calories = [6,5,0,0], k = 2, lower = 1, upper = 5
<strong>输出：</strong>0
<strong>解释：</strong>calories[0] + calories[1] > upper, calories[2] + calories[3] < lower, 总分 = 0.
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= calories.length <= 10^5</code></li>
	<li><code>0 <= calories[i] <= 20000</code></li>
	<li><code>0 <= lower <= upper</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n=calories.size(),sum=0,ans;
        for(int i=0;i<n&&i+k<=n;i++)
        {
            ans=0;
            for(int j=0;j<k;j++)
                ans+=calories[i+j];
            if(ans<lower) sum -=1;
            if(ans>upper) sum +=1;
        }
        return sum;
    }
};

```