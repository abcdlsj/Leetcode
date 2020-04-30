// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> vis(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(res, path, nums, vis, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> path, vector<int> nums, vector<bool> vis, int start) {
        res.push_back(path);
        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i - 1] && vis[i - 1] == false) continue;
            path.push_back(nums[i]);
            vis[i] = true;
            backtrack(res, path, nums, vis, i + 1);
            vis[i] = false;
            path.pop_back();
        }
    }
};
