// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backtrack(res, path, 0, 0, n);
        return res;
    }
    void backtrack(vector<string> &res, const string &path, int left, int right, int n) {
        if(right > left || left > n || right > n) return;

        if(right == left && left == n) {
            res.push_back(path);
        }

        backtrack(res, path + "(", left + 1, right, n);
        backtrack(res, path + ")", left, right + 1, n);
    }
};
