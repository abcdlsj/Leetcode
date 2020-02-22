# Product of the Last K Numbers **
- 题目地址: [https://leetcode-cn.com/problems/product-of-the-last-k-numbers](https://leetcode-cn.com/problems/product-of-the-last-k-numbers)
- 执行时间: 2160 ms
- 内存消耗: 62.8 MB
- 通过日期: 2020-02-16 10:59

## 题目内容
<p>请你实现一个「数字乘积类」<code>ProductOfNumbers</code>，要求支持下述两种方法：</p>

<p>1.<code> add(int num)</code></p>

<ul>
	<li>将数字 <code>num</code> 添加到当前数字列表的最后面。</li>
</ul>

<p>2.<code> getProduct(int k)</code></p>

<ul>
	<li>返回当前数字列表中，最后 <code>k</code> 个数字的乘积。</li>
	<li>你可以假设当前列表中始终 <strong>至少</strong> 包含 <code>k</code> 个数字。</li>
</ul>

<p>题目数据保证：任何时候，任一连续数字序列的乘积都在 32-bit 整数范围内，不会溢出。</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

<strong>输出：</strong>
[null,null,null,null,null,null,20,40,0,null,32]

<strong>解释：</strong>
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32 
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>add</code> 和 <code>getProduct</code> 两种操作加起来总共不会超过 <code>40000</code> 次。</li>
	<li><code>0 <= num <= 100</code></li>
	<li><code>1 <= k <= 40000</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class ProductOfNumbers {
public:
    vector<int> Num;
    ProductOfNumbers() {
    }
    
    void add(int num) {
      Num.push_back(num);  
    }
    
    int getProduct(int k) {
      int pro = 1;
      for(int i = Num.size()-k;i<Num.size();i++){
        if(Num[i]==0) {
          pro = 0;break;
        }
        pro *= Num[i];
      }
      return pro;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

```