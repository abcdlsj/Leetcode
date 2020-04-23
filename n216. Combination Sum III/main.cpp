// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, 0, 1, k, n);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, int sum, int start, int k, int n) {
        if(sum > n) return;
        if(sum == n && path.size() == k) res.push_back(path);
        for(int i = start; i <= 9; i++) {
            path.push_back(i);
            backtrack(res, path, sum + i, i + 1, k, n);
            path.pop_back();
        }
    }
};
