# 栈的压入、弹出序列 LCOF **
- 题目地址: [https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof)
- 执行时间: 20 ms
- 内存消耗: 15.1 MB
- 通过日期: 2020-04-27 20:43

## 题目内容
<p>输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
<strong>输出：</strong>true
<strong>解释：</strong>我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>1 不能在 2 之前弹出。
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>0 <= pushed.length == popped.length <= 1000</code></li>
	<li><code>0 <= pushed[i], popped[i] < 1000</code></li>
	<li><code>pushed</code> 是 <code>popped</code> 的排列。</li>
</ol>

<p>注意：本题与主站 946 题相同：<a href="https://leetcode-cn.com/problems/validate-stack-sequences/">https://leetcode-cn.com/problems/validate-stack-sequences/</a></p>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack; int popidx = 0;
        for(int i = 0; i < pushed.size(); i++) {
            stack.push(pushed[i]);
            while(!stack.empty() && stack.top() == popped[popidx]) {
                popidx++;
                stack.pop();
            }
        }
        return stack.empty();
    }
};

```