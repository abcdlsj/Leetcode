# 包含min函数的栈 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof)
- 执行时间: 44 ms
- 内存消耗: 16.6 MB
- 通过日期: 2020-03-18 22:49

## 题目内容
<p>定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。</p>



<p><strong>示例:</strong></p>

<pre>MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li>各函数的调用总次数不超过 20000 次</li>
</ol>



<p>注意：本题与主站 155 题相同：<a href="https://leetcode-cn.com/problems/min-stack/">https://leetcode-cn.com/problems/min-stack/</a></p>


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
        if(ass.top() == main.top()) ass.pop();
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int min() {
        return ass.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

```