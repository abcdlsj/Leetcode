// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, candidates, target, 0, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates, int target, int start, int sum) {
        if(sum > target) return;
        if(sum == target) res.push_back(path);
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtrack(res, path, candidates, target, i + 1, sum + candidates[i]);
            path.pop_back();
        }
    }
};
