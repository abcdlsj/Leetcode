// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack; int popidx = 0;
        for(int i = 0; i < pushed.size(); i++) {
            stack.push(pushed[i]);
            while(!stack.empty() && stack.top() == popped[popidx]) {
                popidx++;
                stack.pop();
            }
        }
        return stack.empty();
    }
};
