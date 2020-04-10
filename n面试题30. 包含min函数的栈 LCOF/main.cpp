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
