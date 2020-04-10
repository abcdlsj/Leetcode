// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class MyStack {
public:
    queue<int> deque;
    /** Initialize your data structure here. */
    MyStack() { 
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //移到队头
        int size = deque.size(), tmp;
        deque.push(x);
        while(size--) {
            tmp = deque.front();
            deque.pop();
            deque.push(tmp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = deque.front();
        deque.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return deque.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return deque.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
