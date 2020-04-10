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
