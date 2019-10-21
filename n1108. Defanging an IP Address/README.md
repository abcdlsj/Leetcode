# Defanging an IP Address *
- 题目地址: [https://leetcode-cn.com/problems/defanging-an-ip-address](https://leetcode-cn.com/problems/defanging-an-ip-address)
- 执行时间: 4 ms 
- 内存消耗: 8.1 MB
- 通过日期: 2019-09-18 11:13

## 题目内容
<p>给你一个有效的 <a href="https://baike.baidu.com/item/IPv4" target="_blank">IPv4</a> 地址 <code>address</code>，返回这个 IP 地址的无效化版本。</p>

<p>所谓无效化 IP 地址，其实就是用 <code>"[.]"</code> 代替了每个 <code>"."</code>。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>address = "1.1.1.1"
<strong>输出：</strong>"1[.]1[.]1[.]1"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>address = "255.100.50.0"
<strong>输出：</strong>"255[.]100[.]50[.]0"
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li>给出的 <code>address</code> 是一个有效的 IPv4 地址</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string defangIPaddr(string address) {
        for(int i = address.size(); i >= 0; i--){
            if(address[i] == '.'){
                address.replace(i, 1, "[.]");
            }
        }
        return address;
    }
};

```