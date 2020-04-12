// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        if(candidates.size() == 0) return res;
        vector<int> path;
        backtrack(candidates, res, path, 0, target);
        return res;
    }
    void backtrack(vector<int> candidates, vector<vector<int>> &res, vector<int> path, int start, int target) {
        if(accumulate(path.begin(), path.end(), 0) == target) {
            res.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] + accumulate(path.begin(), path.end(), 0) > target) return;
            path.push_back(candidates[i]);
            backtrack(candidates, res, path, i, target);
            path.pop_back();
        }
    }
};
