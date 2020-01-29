# Can Place Flowers 
- 题目地址: [https://leetcode-cn.com/problems/can-place-flowers](https://leetcode-cn.com/problems/can-place-flowers)
- 执行时间: 20 ms
- 内存消耗: 10.4 MB
- 通过日期: 2019-08-25 14:40

## 题目内容
<p>假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。</p>

<p>给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 <strong>n </strong>。能否在不打破种植规则的情况下种入 <strong>n </strong>朵花？能则返回True，不能则返回False。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> flowerbed = [1,0,0,0,1], n = 1
<strong>输出:</strong> True
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> flowerbed = [1,0,0,0,1], n = 2
<strong>输出:</strong> False
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>数组内已种好的花不会违反种植规则。</li>
	<li>输入的数组长度范围为 [1, 20000]。</li>
	<li><strong>n</strong> 是非负整数，且不会超过输入数组的大小。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.empty()) return false;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0                              //当前位置为0
              &&(i-1==-1||flowerbed[i-1]==0)                //前一位置为0，或索引为-1
              &&(i+1==flowerbed.size()||flowerbed[i+1]==0)) //后一位置为0，或索引为flowerbed.size()
            {
                n--;
                flowerbed[i]=1;                
            }        
        }
        return n<=0?true:false;
    }
};

```