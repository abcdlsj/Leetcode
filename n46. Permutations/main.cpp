// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> vis(nums.size(), false);
        backtrack(res, path, nums, vis);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> path, vector<int> nums, vector<bool> vis) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(vis[i] == true) continue;
            path.push_back(nums[i]);
            vis[i] = true;
            backtrack(res, path, nums, vis);
            path.pop_back();
            vis[i] = false;
        }
    }
};
