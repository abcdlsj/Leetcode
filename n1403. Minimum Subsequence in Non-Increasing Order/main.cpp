// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() == 0) return {};
        sort(nums.rbegin(), nums.rend());
        int i = 0;
        vector<int> path;
        while(accumulate(path.begin(), path.end(), 0) <= (accumulate(nums.begin(), nums.end(), 0) / 2)) {
            path.push_back(nums[i]);
            i++;
        }
        return path;
    }
};
