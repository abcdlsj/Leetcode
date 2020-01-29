# Minimum Absolute Difference 
- 题目地址: [https://leetcode-cn.com/problems/minimum-absolute-difference](https://leetcode-cn.com/problems/minimum-absolute-difference)
- 执行时间: 116 ms
- 内存消耗: 18.6 MB
- 通过日期: 2019-09-22 11:04

## 题目内容
<p>给你个整数数组 <code>arr</code>，其中每个元素都 <strong>不相同</strong>。</p>

<p>请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,1,3]
<strong>输出：</strong>[[1,2],[2,3],[3,4]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,3,6,10,15]
<strong>输出：</strong>[[1,3]]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [3,8,-10,23,19,-4,-14,27]
<strong>输出：</strong>[[-14,-10],[19,23],[23,27]]
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= arr.length <= 10^5</code></li>
	<li><code>-10^6 <= arr[i] <= 10^6</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> cnt(arr);
        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;++i){
            cnt[i] = arr[i+1]-arr[i];
        }
        int min=cnt[0];
        for(int i=0;i<arr.size()-1;++i)
            if(min>cnt[i]) min=cnt[i];

        for(int i=0;i<arr.size()-1;++i){
            if(cnt[i]==min) {
                vector<int> bns;
                bns.push_back(arr[i]);
                bns.push_back(arr[i+1]);
                ans.push_back(bns);
            }
        }
        return ans;
    }
};

```