// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }

    void dfs(vector<string> &res, const string &path, int left, int right, int n) {
        if(left > n || right > n || right > left) return;
        if(left == n && right == n) {
            res.push_back(path);
            return;
        } 
        dfs(res, path + '(', left + 1, right, n);
        dfs(res, path + ')', left, right + 1, n);
    }
};

