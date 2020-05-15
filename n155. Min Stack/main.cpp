// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class MinStack {
public:
    stack<int> dataStack;
    stack<int> minStack;
    /** initialize our data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        dataStack.push(x);
        if(minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
    
    void pop() {
        if(minStack.top() == dataStack.top()) {
            minStack.pop();
        }
        dataStack.pop();

    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
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
