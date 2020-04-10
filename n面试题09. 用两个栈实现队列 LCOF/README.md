# 用两个栈实现队列 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof)
- 执行时间: 716 ms
- 内存消耗: 103.5 MB
- 通过日期: 2020-04-06 13:07

## 题目内容
<p>用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 <code>appendTail</code> 和 <code>deleteHead</code> ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，<code>deleteHead</code> 操作返回 -1 )</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
<strong>输出：</strong>[null,null,3,-1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
<strong>输出：</strong>[null,-1,null,null,5,2]
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= values <= 10000</code></li>
	<li><code>最多会对 appendTail、deleteHead 进行 10000 次调用</code></li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class CQueue {
public:
    stack<int> stackPush;
    stack<int> stackPop;
    
    CQueue() {
    }
    
    void appendTail(int value) {
        stackPush.push(value);
    }
    
    int deleteHead() {
        if(stackPop.empty()) {
            if(stackPush.empty()) {
                return -1;
            } else {
                while(!stackPush.empty()) {
                    stackPop.push(stackPush.top());
                    stackPush.pop();
                }
            }
        }
        int top = stackPop.top();
        stackPop.pop();
        return top;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

```