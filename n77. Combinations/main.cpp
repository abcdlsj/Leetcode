// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, n, k, 1);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, int n, int k, int start) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        for(int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrack(res, path, n, k, i+1);
            path.pop_back();
        }
    }
};
