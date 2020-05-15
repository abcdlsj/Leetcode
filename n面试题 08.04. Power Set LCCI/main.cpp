// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;

        backtrack(res, path, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, const vector<int> &nums, int start) {
        res.push_back(path);

        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(res, path, nums, i + 1);
            path.pop_back();
        }
    }
};
