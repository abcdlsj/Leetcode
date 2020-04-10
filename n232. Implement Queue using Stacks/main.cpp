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
