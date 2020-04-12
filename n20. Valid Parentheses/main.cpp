// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        stack.push('#');
        vector<int> cnt(150);
        cnt['('] = ')'; cnt['['] = ']'; cnt['{'] = '}';
        for(auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[')
                stack.push(ch);
            else if(ch == cnt[stack.top()]) stack.pop();
            else return false;
        }
        if(stack.top() == '#') return true;
        return false;
    }
};
