# Min Stack *
- 题目地址: [https://leetcode-cn.com/problems/min-stack](https://leetcode-cn.com/problems/min-stack)
- 执行时间: 92 ms
- 内存消耗: 15.3 MB
- 通过日期: 2020-04-01 00:08

## 题目内容
<p>设计一个支持 <code>push</code> ，<code>pop</code> ，<code>top</code> 操作，并能在常数时间内检索到最小元素的栈。</p>

<ul>
	<li><code>push(x)</code> —— 将元素 x 推入栈中。</li>
	<li><code>pop()</code> —— 删除栈顶的元素。</li>
	<li><code>top()</code> —— 获取栈顶元素。</li>
	<li><code>getMin()</code> —— 检索栈中的最小元素。</li>
</ul>



<p><strong>示例:</strong></p>

<pre><strong>输入：</strong>
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

<strong>输出：</strong>
[null,null,null,null,-3,null,0,-2]

<strong>解释：</strong>
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>pop</code>、<code>top</code> 和 <code>getMin</code> 操作总是在 <strong>非空栈</strong> 上调用。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class MinStack {
public:
    stack<int> main;
    stack<int> ass;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        main.push(x);
        if(ass.empty() || ass.top() >= x) ass.push(x);
    }
    
    void pop() {
        if(main.top() == ass.top()) ass.pop();
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return ass.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

```