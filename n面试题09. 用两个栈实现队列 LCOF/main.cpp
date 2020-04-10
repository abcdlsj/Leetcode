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
