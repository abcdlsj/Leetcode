# Implement Queue using Stacks *
- 题目地址: [https://leetcode-cn.com/problems/implement-queue-using-stacks](https://leetcode-cn.com/problems/implement-queue-using-stacks)
- 执行时间: 0 ms
- 内存消耗: 6.8 MB
- 通过日期: 2020-04-06 18:59

## 题目内容
<p>使用栈实现队列的下列操作：</p>

<ul>
	<li>push(x) -- 将一个元素放入队列的尾部。</li>
	<li>pop() -- 从队列首部移除元素。</li>
	<li>peek() -- 返回队列首部的元素。</li>
	<li>empty() -- 返回队列是否为空。</li>
</ul>

<p><strong>示例:</strong></p>

<pre>MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>你只能使用标准的栈操作 -- 也就是只有 <code>push to top</code>, <code>peek/pop from top</code>, <code>size</code>, 和 <code>is empty</code> 操作是合法的。</li>
	<li>你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。</li>
	<li>假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class MyQueue {
public:
    stack<int> main;
    stack<int> help;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        main.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!main.empty()) {
            help.push(main.top());
            main.pop();
        }
        int popnum = help.top();
        help.pop();
        while(!help.empty()) {
            main.push(help.top());
            help.pop();
        }
        return popnum;
    }
    
    /** Get the front element. */
    int peek() {
        while(!main.empty()) {
            help.push(main.top());
            main.pop();
        }
        int popnum = help.top();
        while(!help.empty()) {
            main.push(help.top());
            help.pop();
        }
        return popnum;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

```