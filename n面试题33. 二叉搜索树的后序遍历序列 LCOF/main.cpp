// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stack;
        int prevElem = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; i--) {
            if(postorder[i] > prevElem) return false;
            while(!stack.empty() && postorder[i] < stack.top()) {
                prevElem = stack.top();
                stack.pop();
            }
            stack.push(postorder[i]);
        }
        return true;
    }
};
