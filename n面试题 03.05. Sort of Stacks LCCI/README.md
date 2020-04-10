# Sort of Stacks LCCI **
- 题目地址: [https://leetcode-cn.com/problems/sort-of-stacks-lcci](https://leetcode-cn.com/problems/sort-of-stacks-lcci)
- 执行时间: 416 ms
- 内存消耗: 47 MB
- 通过日期: 2020-04-06 18:48

## 题目内容
<p>栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：<code>push</code>、<code>pop</code>、<code>peek</code> 和 <code>isEmpty</code>。当栈为空时，<code>peek</code> 返回 -1。</p>

<p><strong>示例1:</strong></p>

<pre><strong> 输入</strong>：
["SortedStack", "push", "push", "peek", "pop", "peek"]
[[], [1], [2], [], [], []]
<strong> 输出</strong>：
[null,null,null,1,null,2]
</pre>

<p><strong>示例2:</strong></p>

<pre><strong> 输入</strong>： 
["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
[[], [], [], [1], [], []]
<strong> 输出</strong>：
[null,null,null,null,null,true]
</pre>

<p><strong>说明:</strong></p>

<ol>
	<li>栈中的元素数目在[0, 5000]范围内。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class SortedStack {
private:
    stack<int> main;
    stack<int> help;

public:
    SortedStack() {
    }
    
    void push(int val) {
        while(!isEmpty() && main.top() < val) {
            help.push(main.top());
            main.pop();
        }

        main.push(val);

        while(!help.empty()) {
            main.push(help.top());
            help.pop();
        }
    }
    
    void pop() {
        if(!isEmpty())
            main.pop();
    }
    
    int peek() {
        return isEmpty() ? -1 : main.top();
    }
    
    bool isEmpty() {
        return main.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

```